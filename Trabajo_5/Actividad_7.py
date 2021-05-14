i=1500
resta=170
pi='3.'
while i>0:
    cond=1
    decimal = 0
    while cond == 1:
        resta=resta-120
        if resta >= 0:
            decimal=decimal+1
        elif resta < 0:
            resta=resta+120
            pi=pi+str(decimal)
            resta=resta*10
            cond=0
    i=i-1

print(pi)
