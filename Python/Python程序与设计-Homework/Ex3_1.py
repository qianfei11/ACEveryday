import time
import datetime
print(time.time())
print(datetime.date.today())
def get_today_a_month_ago():
    today = datetime.date.today()
    if(today.month - 1 < 0):
        month = (today.month + 11) % 12
        year = today.year - 1
        today = today.replace(year=year, month=month)
    else:
        month = today.month - 1
        today = today.replace(month=month)
    return today
if __name__ == '__main__':
    today = get_today_a_month_ago()
    print(today)