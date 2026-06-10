import (
	"math/big"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcmBig(a *big.Int, b int) *big.Int {
	g := gcd(int(a.Int64()), b)

	res := new(big.Int).Div(a, big.NewInt(int64(g)))
	res.Mul(res, big.NewInt(int64(b)))

	return res
}

func maxLength(nums []int) int {
	n := len(nums)
	ans := 0

	for i := 0; i < n; i++ {
		prod := big.NewInt(1)
		lcm := big.NewInt(1)
		g := 0

		for j := i; j < n; j++ {
			prod.Mul(prod, big.NewInt(int64(nums[j])))

			if j == i {
				g = nums[j]
			} else {
				g = gcd(g, nums[j])
			}

			lcm = lcmBig(lcm, nums[j])

			right := new(big.Int).Mul(
				new(big.Int).Set(lcm),
				big.NewInt(int64(g)),
			)

			if prod.Cmp(right) == 0 {
				if j-i+1 > ans {
					ans = j - i + 1
				}
			}
		}
	}

	return ans
}
