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

def LinksParsing(link:str, fileadress:str):
    file=open(fileadress, "a+", encoding="utf-8")
    r=requests.get(link)
    html=BS(r.content, 'html.parser')
    for e in html.select(".agency-lines"):
        title=e.select(".line-title-wrapper > strong")
        href=e.select("li.mobile-line > a[href]")
    for e in range(0, len(title)):
        href[e].string=""
        output=[str(title[e].get_text()),".",str(href[e]).replace('<a href="','').replace('"></a>',''),"\n"]
        file.writelines(output)
    file.write("\n")
    file.close()

def LoopForPrzystanki(fileIn:str,fileOut:str):
    fileI=open(fileIn, encoding="utf-8")
    fileO=open(fileOut, "a+", encoding="utf-8")
    for e in fileI:
        e=e.strip()
        href=e[e.find(".")+1:len(e)]
        if(e!=""):
            title=e[0:e.find(".")]
            #out1=["a",title, "="]
            #print(href," ",title," ",end="\n")
            #output=[title,"=",PrzystankiParsing(href),"\n"]
            print(title,".",len(PrzystankiParsing(href)),"=",PrzystankiParsing(href), end="\n", sep="")
#             fileO.writelines(out1)
#             fileO.write("[")
#             for el in PrzystankiParsing(href):
#                 out2=[el,","]
#                 fileO.writelines(out2)
#             fileO.write("]")
#             fileO.write("\n")
            
    fileI.close()
    fileO.close()

print(PrzystankiParsing("https://moovitapp.com/index/pl/transport_publiczny-line-278-Krakow-5499-1373692-4689842-0"))
#LinksParsing("https://moovitapp.com/index/pl/transport_publiczny-lines-Krakow-5499-1373692","xz.txt")
#LoopForPrzystanki("xz.txt","forsqlite.txt")