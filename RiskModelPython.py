from random import Random
import matplotlib.pyplot as plt


random = Random()
for year in range(20):
    Average, Highest, amount = 0, 0, []

    for count in range(100):
        ClaimAmounts = random.lognormvariate(9, 1.5)
        amount.append(ClaimAmounts)

    Average = sum(amount)/100
    Highest = max(amount)
    print ("Year: ", year + 1)
    print ("Average Claim Amount: ", Average)
    print ("Highest Claim Amount: ", Highest)
    print ("Total Claim Amount: ", sum(amount))
    plt.hist(amount, bins=50)
    plt.title ("Year: " + str(year + 1) + " Claim Amounts Distribution")
    plt.xlabel("amount")
    plt.ylabel("Frequency")
    plt.show()
