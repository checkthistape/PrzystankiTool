import requests
from bs4 import BeautifulSoup as BS

def PrzystankiParsing(link:str):
    #output:list[str]=[]
    #file=open("", encoding="utf-8")
    #for 
    r=requests.get(link)
    html=BS(r.content, 'html.parser')
    for e in html.select(".stops-wrapper"):
        title=str(e.select(".stop-container h3"))
        title=title.replace("<h3>","")
        title=title.replace("</h3>","")
        title=title.replace("[","")
        title=title.replace("]","")
        print(title)
    print("\n")
    for ee in title:
        print(ee, end="")
        
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
    file.write("\nkuuuuul\n")
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
        e=e.replace('<strong class="line-title">',"")
        e=e.replace('</strong>',"")
        e=e.replace('[',"")
        e=e.replace(']',"")
        e=e.replace(' ',"")
        e=e.replace(',',"")
        e=e.replace('<ahref="',"")
        i+=1
        if(e=="kuuuuul\n"):
            if(i%2==0):
                i+=1
            e=e.replace("kuuuuul","")
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
        
PrzystankiParsing("https://moovitapp.com/index/pl/transport_publiczny-line-1-Krakow-5499-1373691-4689589-0")        
#parsing("https://moovitapp.com/index/pl/transport_publiczny-lines-Krakow-5499-1373691","parsing.txt")      
#analyze("parsing.txt","f.txt")