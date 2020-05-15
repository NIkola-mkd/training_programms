import pandas
from sklearn.ensemble import RandomForestClassifier

trips = pandas.read_excel("trips_data.xlsx")

trips.head()
trips.describe()
trips.salary.hist()
trips.city.value_counts()
trips.city.value_counts().plot(kind='bar')
trips.vacation_preference.value_counts().plot(kind='bar')
trips.transport_preference.value_counts().plot(kind='bar')

trips.head()

trips_updated =  pandas.get_dummies(trips, columns=['city', 'vacation_preference', 'transport_preference'])
input_data = trips_updated.drop('target', axis=1)
target = trips_updated.target
model = RandomForestClassifier()


model.fit(input_data, target)

# {col: 0 for col in input_data.columns}
my_sample = {'salary': 50000,
 'age': 30,
 'family_members': 1,
 'city_Екатеринбург': 1,
 'city_Киев': 0,
 'city_Краснодар': 0,
 'city_Минск': 0,
 'city_Москва': 0,
 'city_Новосибирск': 0,
 'city_Омск': 0,
 'city_Петербург': 0,
 'city_Томск': 0,
 'city_Хабаровск': 0,
 'city_Ярославль': 0,
 'vacation_preference_Архитектура': 0,
 'vacation_preference_Ночные клубы': 0,
 'vacation_preference_Пляжный отдых': 0,
 'vacation_preference_Шоппинг': 1,
 'transport_preference_Автомобиль': 0,
 'transport_preference_Космический корабль': 0,
 'transport_preference_Морской транспорт': 0,
 'transport_preference_Поезд': 0,
 'transport_preference_Самолет': 1}
my_sample_dataFrame = pandas.DataFrame(data=[my_sample])
my_sample_dataFrame
model.predict(my_sample_dataFrame)
