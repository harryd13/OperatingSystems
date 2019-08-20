class process():
    def __init__(self,pid,AT,BT):
        self.pid = pid
        self.AT = AT
        self.BT = BT
        self.CT = 0
        self.tat = 0
        self.WT = 0
        self.pcb = 0
    def __str__(self):
        return f"|{self.pid}\t|{self.AT}\t|{self.BT}\t|{self.CT}\t|{self.tat}\t|{self.WT}"

def print_all_process(process_list):
    print("|pid"+"\t|"+"AT"+"\t|"+"BT"+"\t|"+"CT"+"\t|"+"tat"+"\t|"+"WT")
    for p in process_list:
        print(p)

processes = []
ready_queue = []
completed_process = []
processes_copy = processes.copy()

p1 = process(1,0,5)
p2 = process(2,3,1)
p3 = process(3,1,2)
p4 = process(4,2,3)

processes = [p1,p2,p3,p4]
processes.sort(key = lambda p:p.AT)

bt = []
for p in processes:
    bt.append(p.BT)

print_all_process(processes)
t = 0
while True:
    #if t > At of last process and queue is empty, break
    if(t > processes[-1].AT) and ready_queue == []:
        break
    #all the ready process at Time = t should move to ready queue
    for p in processes:
        if(p.AT <= t) and p.pcb == 0:
            p.pcb = -1
            ready_queue.append(p)

            
    #now all the processes in ready q should be sorted according to burst time
    ready_queue.sort(key = lambda pro:pro.BT)
    
    #now take the scheduled process and remove 1 bt from it
    ready_queue[0].BT -= 1

    #now check if it is completed
    if(ready_queue[0].BT == 0):
        #process terminated
        #CT updated,pushed in completed queue and popped of ready q
        ready_queue[0].CT = t + 1
        completed_process.append(ready_queue[0])
        ready_queue.pop(0)
    t += 1


completed_process.sort(key = lambda p:p.AT)

for i in range(4):
    completed_process[i].BT = bt[i]
    

print("__________________________________________________\n\n\n")

for i in range(4):
    completed_process[i].tat = completed_process[i].CT - completed_process[i].AT
    completed_process[i].WT = completed_process[i].tat - completed_process[i].BT
    
s = 0
for p in completed_process:
    s = s + p.WT
    

print_all_process(completed_process)
print(f"The avg Waiting time = {s/len(completed_process)}")


        

