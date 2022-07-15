def getHammingDistance(reference, target):
    difference = []

    for i, data in enumerate(reference):
        if target[i] != data:
            difference.append(i)

    return difference


def getHammingPath(difference):
    path = [a]
    visited = []

    i = 0
    while len(visited) != (codeCount - 2) and len(difference) != 0:
        if i == a or i in visited:
            i += 1
            continue
        HammingDistance = getHammingDistance(codeList[path[len(path) - 1]], codeList[i])
        if len(HammingDistance) == 1 and HammingDistance[0] in difference:
            path.append(i)
            visited.append(i)
            difference.remove(HammingDistance[0])

        i += 1
        if i >= codeCount:
            i = 0

    if len(difference) == 0:
        return path
    else:
        return None


print("입력하세요.")

codeCount, codeLength = map(int, input().split())
codeList = []
pathList = []

for i in range(codeCount):
    codeList.append(input())

a, b = map(int, input().split())
a, b = a - 1, b - 1

a_b_difference = getHammingDistance(codeList[a], codeList[b])
pathList.append(getHammingPath(a_b_difference))
# for i in range(codeCount):
    # if i == a or i == b:
        # continue
    # pathList.append(getHammingPath(a_b_difference))

print(pathList)
