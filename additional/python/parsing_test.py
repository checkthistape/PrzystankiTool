import requests
from bs4 import BeautifulSoup as BS

def PrzystankiParsing(link:str):
    output:list[str]=[]
    r=requests.get(link)
    html=BS(r.content, 'html.parser')
    for e in html.select(".stops-wrapper"):
        title=e.select(".stop-container h3")
        for ee in title:
            output.append(ee.text)
    return output
        
def LinksParsing(link:str, file:str):
    fileErase=open(file, "w", encoding="utf-8")
    fileErase.close()
    file=open(file, "a+", encoding="utf-8")
    r=requests.get(link)
    html=BS(r.content, 'html.parser')
    for e in html.select(".agency-lines"):
        title=str(e.select(".mobile-line strong"))
        href=str(e.select(".mobile-line a"))
        
    for ee in title:
        file.write(ee)
        if(ee==","):
            file.write("\n")
    file.write("\ndamn\n")
    for el in href:
        file.write(el)
        if(el==","):
            file.write("\n")
    file.close()

def LinksAnalyze(fileInput:str, fileOutput:str):
    fileIn=open(fileInput, encoding="utf-8")
    fileOut=open(fileOutput, "a+",encoding="utf-8")
    i:int=0
    status:bool=False
    for e in fileIn:
        i+=1
        if(e=="damn\n"):
            if(i%2==0):
                i+=1
            e=e.replace("damn","")
            fileOut.write("\n")
            status=True
        if(status==False):
            fileOut.write(e)
        if(i%2==0 and status==True):
            Opos=e.find("-0")
            fileOut.write(e[:Opos+2])
            fileOut.write("\n")
    fileOut.write("\n")
    fileIn.close()
    fileOut.close()
        

LinksParsing("https://moovitapp.com/index/pl/transport_publiczny-lines-Krakow-5499-1373691")

