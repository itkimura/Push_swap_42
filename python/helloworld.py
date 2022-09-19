import sys

args = sys.argv
value = [200, 50, 130, 90, 250, 61, 110, 88, 33, 80, 70, 159, 180, 20, 2000]

def main():
    print("Original:\n")
    for i in range(len(value)):
            print("i = %d" %(value[i]))
    newlist = sorted(value)
    print("\nSorted:\n")
    for i in range(len(newlist)):
            print("i = %d" %(newlist[i]))
    for i in range(len(value)):
        for j in range(len(newlist)):
            if value[i] == newlist[j]:
                value[i].keys = j
    print("\nWith key\n")
    for i in range(len(value)):
            print("i = %d key" %(value[i], value[i].key))


if __name__ == "__main__":
    main()
