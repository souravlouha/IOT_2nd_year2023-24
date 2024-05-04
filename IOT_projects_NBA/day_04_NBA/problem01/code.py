import sys
import urllib.request
from time import sleep
import Adafruit_DHT as dht

# Enter Your API key here
myAPI = 'T0RGBR7N1ARD9XWB0000' // thingspeak write api key
# URL where we will send the data, Don't change it
baseURL = 'https://api.thingspeak.com/update?api_key=%s' % myAPI 

def DHT11_data():
# Reading from DHT11 and storing the temperature and humidity
        humi, temp = dht.read_retry(dht.DHT11, 21) 
        return humi, temp

while True:
        try:
                humi, temp = DHT11_data()

# If Reading is valid
                if isinstance(humi, float) and isinstance(temp, float):
        # Formatting to two decimal places
                    humi = '%.2f' % humi   
                    temp = '%.2f' % temp
                    print(humi)
                    print(temp)

# Sending the data to thingspeak
                    conn = urllib.request.urlopen(baseURL + '&field1=%s&field2=%s' % (temp, humi))
                    conn.read()
# Closing the connection
                    conn.close()

                else:
                    print ('Error')

# DHT11 requires 2 seconds to give a reading, so make sure to add delay of above 2 seconds.
                sleep(20)

        except:
                break