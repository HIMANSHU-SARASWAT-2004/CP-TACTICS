vi get_best3(vector<int> &a) {
    int mx1 = -1, mx2 = -1, mx3 = -1;
    for (int i = 0; i < a.size(); ++i) {
        if (mx1 == -1 || a[i] > a[mx1]) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        } else if (mx2 == -1 || a[i] > a[mx2]) {
            mx3 = mx2;
            mx2 = i;
        } else if (mx3 == -1 || a[i] > a[mx3]) {
            mx3 = i;
        }
    } vi res = {mx1, mx2, mx3};
    return res;
}
