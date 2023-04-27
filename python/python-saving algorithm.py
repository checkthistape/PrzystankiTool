def saving():
    output:list[str]=[]
    fileInput=open("przystanki.txt", encoding="utf-8")
    fileOutput=open("output.txt",encoding="utf-8")
    for e in fileInput.readlines():
        e=e.replace("NAJBLIŻSZE PRZYJAZDY", "")
        if(e!='\n' and e!=""):
            output.append(e.strip())
                   
    fileInput.close()
    fileOutput.close()
    
def barriers(n:int):
    file=open("result.txt", "a+", encoding="utf-8")
    for e in range(0,n):
        file.write("\n.¯¯¯¯¯¯¯¯¯¯¯.¯¯¯¯¯¯¯¯¯¯¯.\n\n")
        file.write(".___________.___________.\n\n")
        
        
        
saving()
    
    
