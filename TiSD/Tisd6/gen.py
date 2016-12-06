for i in range(10):
	f=open(str((i+1)*100)+".txt","w")
	for j in range((i+1)*100):
		f.write(str(j)+"\n")
	f.close()
