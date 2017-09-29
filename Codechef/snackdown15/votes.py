test_cases = int(raw_input())

for i in range(0, test_cases):
    number_of_people = int(raw_input())
    input_voting = raw_input().split()
    voting = [(int(idx)+1, int(val)) for idx, val in enumerate(input_voting)]
    
    if sum([x[1] for x in voting])!=number_of_people or max([x[1] for x in voting])==number_of_people:
        print -1
    else:
        newvoting = sorted(voting, key=lambda x: x[1], reverse=True)
        final = []
        for i in range(0, len(newvoting)):
            number_of_votes = newvoting[i][1]
            whose_vote = newvoting[i][0]
            start = i+1
            while(number_of_votes>0):
                if start != i and start<len(newvoting):
                    if len(newvoting[start])<3:
                        newvoting[start] = newvoting[start]+(whose_vote,)
                        number_of_votes = number_of_votes-1
                if start>=len(newvoting):
                    start=0
                else:
                    start+=1
    	newvoting = sorted(newvoting, key=lambda x: x[0])
        print ' '.join([str(x[2]) for x in newvoting])
