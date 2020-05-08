"""
Протокол ТСР
"""
import asyncio
from asyncio import transports


# from typing import Optional


class ClientProtocol(asyncio.Protocol):
    login: str
    server: 'Server'
    transport: transports.Transport

    def __init__(self, server: 'Server'):
        self.server = server
        self.login = None

    def data_received(self, data: bytes):
        decoded = data.decode()
        print(decoded)

        if self.login is None:
            # login:User
            if decoded.startswith("login:"):
               # self.login = decoded.replace("login:", "").replace("\r\n", "")
                temp_login = decoded.replace("login:", "").replace("\r\n", "")

                for user in self.server.clients:
                    if user.login == temp_login:
                        self.transport.write("Этот логин уже занят. Попробуйте другой")
                        self.transport.close()
                        return

                self.transport.write(
                    f"Привет, {self.login}!".encode()
                )
                self.send_history()
            else:
                self.send_message(decoded)

    def send_history(self):
        last_messages = self.server.messages[-10:]

        for x in last_messages:
            self.transport.write(x.encode())

    def send_message(self, message):
        format_string = f"<{self.login}> {message}"
        self.server.messages.append(format_string)
        encoded = format_string.encode()

        for client in self.server.clients:
            if client.login != self.login:
                client.transport.write(encoded)

    def connection_made(self, transport: transports.Transport):
        self.transport = transport
        self.server.clients.append(self)
        print("Соединение установлено")

    def connection_lost(self, exception):
        self.server.clients.remove(self)
        print("Соединение разорвано")


class Server:
    clients: list
    messages: list

    def __init__(self):
        self.clients = []
        self.messages = []

    def create_protocol(self):
        return ClientProtocol(self)

    async def start(self):
        loop = asyncio.get_running_loop()

        coroutine = await loop.create_server(
            self.create_protocol,
            "127.0.0.1",
            8888
        )

        print("Сервер запущен ...")

        await coroutine.serve_forever()


process = Server()
try:
    asyncio.run(process.start())
except KeyboardInterrupt:
    print("Сервер остановлен вручную")
