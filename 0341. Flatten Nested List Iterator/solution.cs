public class NestedIterator {
    private Stack<IEnumerator<NestedInteger>> stack;
    private int nextVal;
    private bool hasNextCached;

    public NestedIterator(IList<NestedInteger> nestedList) {
        stack = new Stack<IEnumerator<NestedInteger>>();
        stack.Push(nestedList.GetEnumerator());
        hasNextCached = false;
    }

    public bool HasNext() {
        if (hasNextCached) return true;

        while (stack.Count > 0) {
            var it = stack.Peek();

            if (!it.MoveNext()) {
                stack.Pop();
                continue;
            }

            var cur = it.Current;

            if (cur.IsInteger()) {
                nextVal = cur.GetInteger();
                hasNextCached = true;
                return true;
            } else {
                stack.Push(cur.GetList().GetEnumerator());
            }
        }

        return false;
    }

    public int Next() {
        if (!HasNext())
            throw new InvalidOperationException();

        hasNextCached = false;
        return nextVal;
    }
}
