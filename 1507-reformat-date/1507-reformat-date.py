import re
class Solution:
    def reformatDate(self, date: str) -> str:
        date = re.sub(r'(th|nd|rd|st)', "", date)
        dateList = date.split()
        dateMap  = {
            "Jan": "01",
            "Feb": "02",
            "Mar": "03",
            "Apr" : "04",
            "May": "05",
            "Jun": "06",
            "Jul": "07",
            "Aug" : "08",
            "Sep": "09",
            "Oct" : "10",
            "Nov": "11",
            "Dec": "12"
        }

        month = dateMap[dateList[1]]
        year = dateList[2]
        day = dateList[0].rjust(2).replace(" ", "0")

        return year + "-" + month + "-" + day