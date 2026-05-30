import (
    "sort"
    "strconv"
)

func findRelativeRanks(score []int) []string {
    n := len(score)

    type Athlete struct {
        score int
        idx   int
    }

    athletes := make([]Athlete, n)

    for i, s := range score {
        athletes[i] = Athlete{s, i}
    }

    sort.Slice(athletes, func(i, j int) bool {
        return athletes[i].score > athletes[j].score
    })

    ans := make([]string, n)

    for rank, athlete := range athletes {
        switch rank {
        case 0:
            ans[athlete.idx] = "Gold Medal"
        case 1:
            ans[athlete.idx] = "Silver Medal"
        case 2:
            ans[athlete.idx] = "Bronze Medal"
        default:
            ans[athlete.idx] = strconv.Itoa(rank + 1)
        }
    }

    return ans
}
