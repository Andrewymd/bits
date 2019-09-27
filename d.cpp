#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int hailstone(int n) {
    int length = 0;
    while (1 < n)
    {
        (n % 2) ? n = 3 * n + 1 : n /= 2;
        std::cout << n << " ";
        length++;
    }
    return length;
}


void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void InsertSort(int arr[], int length) {
    if (arr == nullptr || length <= 0) {
        throw new std::exception("invalid input");
    }
    int i, j, temp;
    for (i = 1; i < length; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

void SelectSort(int arr[], int length) {
    if (arr == nullptr || length <= 0) {
        throw new std::exception("invalid input");
    }
    int i, j, MinIndex;
    for (i = 0; i < length; i++) {
        MinIndex = i;
        for (j = i + 1; j < length; j++) {
            if (arr[j] < arr[i]) {
                MinIndex = j;
            }
        }
        Swap(arr[i], arr[MinIndex]);
    }
}

void BubbleSort(int arr[], int length) {
    if (arr == nullptr || length <= 0) {
        throw new std::exception("invalid input");
    }
    int i, j, flag, lastSwap;
    for (i = length - 1; i > 0; i=lastSwap) {
        flag = 1;
        lastSwap = 0;
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
                lastSwap = j;
                flag = 0;
            }
        }
        if (flag) {
            return;
        }
    }
}

int Partion(int arr[], int length, int start, int end) {
    if (arr == nullptr || length < 0 || start < 0 || end >=length) {
        throw new std::exception("invalid input");
    }
    /*
    int pivot = arr[start];
    int i = start, j = end;
    while (i < j) {
        while (i<j && arr[j] > pivot) {
            j--;
        }
        if(i<j){
            arr[i++] = arr[j];
        }
        while (i<j && arr[i] <= pivot) {
            i++;
        }
        if(i<j){
            arr[j--] = arr[i];
        }
        //Swap(arr[i], arr[j]);
    }
    a[i] = pivot;
    //Swap(arr[i], arr[start]);
    return i;
    */
    int i = start; //random in range [start, end]
    Swap(arr[i], arr[end]);
    int small = start - 1;
    for (i = start; i < end; ++i) {
        if(arr[i]<arr[end]){
            ++small;
            if (small != i) {
                Swap(arr[i], arr[small]);
            }
        }
    }
    ++small;
    Swap(arr[small], arr[end]);
    return small;
}

void QuickSort(int arr[], int length, int start, int end) {
    if (start == end) {
        return;
    }
    int index = Partion(arr, length, start, end);
    if (index > start) {
        QuickSort(arr, length, start, index - 1);
    }
    if (index < end) {
        QuickSort(arr, length, index + 1, end);
    }
}


void MergeArray(int arr[], int start, int mid, int end, int temp[]) {
    int i = start, j = mid + 1;
    int m = mid, n = end;
    int k = 0;
    while (i <= m&&j <= n) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= m) {
        temp[k++] = arr[i++];
    }
    while (j <= n) {
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; i++) {
        arr[start + i] = temp[i];
    }
}
void MergeSort(int arr[], int start, int end, int temp[]) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid, temp);
        MergeSort(arr, mid + 1, end, temp);
        MergeArray(arr, start, mid, end, temp);
    }
}

void HeapAdjust(int arr[], int i, int length) {
    int NumChild;
    int temp;
    for (temp = arr[i]; 2 * i + 1 < length; i = NumChild) {
        NumChild = 2 * i + 1;
        if (NumChild < length - 1 && arr[NumChild + 1] > arr[NumChild]) {
            ++NumChild;
        }
        if (temp < arr[NumChild]) {
            arr[i] = arr[NumChild];
            arr[NumChild] = temp;
        }
        else {
            break;
        }
    }
}

void HeapSort(int arr[], int length) {

    for (int i = length / 2 - 1; i >= 0; --i) {
        HeapAdjust(arr, i, length);
    }
    for (int i = length - 1; i > 0; --i) {
        Swap(arr[0], arr[i]);
        HeapAdjust(arr, 0, i);
    }
}

void ShellSort(int arr[], int length) {
    int inc, i, j, temp;
    for (inc = length / 2; inc >= 1; inc = inc / 2) {
        for (i = inc; i < length; i++) {
            temp = arr[i];
            for (j = i - inc; j >= 0 && temp < arr[j]; j = j - inc) {
                arr[j + inc] = arr[j];
            }
            arr[j + inc] = temp;
        }
    }
}

struct BST {
    int number;
    struct BST *left;
    struct BST *right;
};

void InsertBST(BST **tree, int v) {
    if (*tree == nullptr) {
        *tree = new BST;
        (*tree)->left = (*tree)->right = nullptr;
        (*tree)->number = v;
        return;
    }
    if (v < (*tree)->number) {
        InsertBST(&((*tree)->left), v);
    }
    else {
        InsertBST(&((*tree)->right), v);
    }
}

void PrintResult(BST *tree) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left != nullptr) {
        PrintResult(tree->left);
    }
    std::cout << tree->number << " ";
    if(tree->right!=nullptr){
        PrintResult(tree->right);
    }
}

void CreateBST(BST **tree, int a[], int length) {
    *tree = nullptr;
    for (int i = 0; i < length; i++) {
        InsertBST(tree, a[i]);
    }
}

void SortAges(int ages[], int length) {
    if (ages == nullptr || length <= 0) {
        return;
    }
    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];
    memset(timesOfAge, 0, oldestAge+1);
    for (int i = 0; i < length; ++i) {
        int age = ages[i];
        if (age<0 || age>oldestAge) {
            throw new std::exception("age out of range");
        }
        ++timesOfAge[age];
    }
    int index = 0;
    for (int i = 0; i <= oldestAge; ++i) {
        for (int j = 0; j < timesOfAge[i]; ++j) {
            ages[index] = i;
            ++index;
        }
    }
}

int maxProduct(int length) {
    if (length < 2) {
        return 0;
    }
    if (length == 2) {
        return 1;
    }
    if (length == 3) {
        return 2;
    }
    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    int max = 0;
    for (int i = 4; i <= length; ++i) {
        max = 0;
        for (int j = 1; j <= i / 2; ++j) {
            int product = products[j] * products[i - j];
            if (max < product) {
                max = product;
            }
        }
        products[i] = max;
    }
    max = products[length];
    delete[] products;
    return max;
}

int maxProduct2(int length) {
    if (length < 2) {
        return 0;
    }
    if (length == 2) {
        return 1;
    }
    if (length == 3) {
        return 2;
    }
    int timesOf3 = length / 3;
    if (length - timesOf3 * 3 == 1)
        timesOf3 -= 1;
    int timesOf2 = (length - timesOf3 * 3) / 2;
    return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
}

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {

    }
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDelete) {
    if (!pListHead || !pToBeDelete) {
        return;
    }
    if (pToBeDelete->next != nullptr) {
        ListNode* pNext = pToBeDelete->next;
        pToBeDelete->val = pNext->val;
        pToBeDelete->next = pNext->next;
    }
    else if (*pListHead == pToBeDelete) {
        delete pToBeDelete;
        pToBeDelete = nullptr;
        *pListHead = nullptr;
    }
    else {
        ListNode* pNode = *pListHead;
        while (pNode->next!=pToBeDelete)
        {
            pNode = pNode->next;
        }
        pNode->next = pToBeDelete->next;
        delete pToBeDelete;
        pToBeDelete = nullptr;
    }
}

ListNode* DeleteDuplication(ListNode* pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    ListNode* preNode = nullptr;
    ListNode* pNode = pHead;
    ListNode* pNext = nullptr;
    while (pNode != nullptr) {
        pNext = pNode->next;
        bool needDelete = false;
        if ((pNext != nullptr) && (pNext->val = pNode->val)) {
            needDelete = true;
        }
        if (!needDelete) {
            preNode = pNode;
            pNode = pNode->next;
        }
        else {
            int val = pNode->val;
            ListNode *pToBeDelete = pNode;
            while (pToBeDelete != nullptr&&pToBeDelete->val == val) {
                pNext = pToBeDelete->next;
                delete pToBeDelete;
                pToBeDelete = nullptr;
                pToBeDelete = pNext;
            }
            if (preNode == nullptr) {
                pHead = pNext;
            }
            else {
                preNode->next = pNext;
            }
            pNode = pNext;
        }
    }
    return pHead;
}

bool matchCore(char* str, char* pattern) {
    if (*str == '\0' && *pattern == '\0') {
        return true;
    }
    if (*str != '\0' && *pattern == '\0') {
        return false;
    }
    if (*(pattern + 1) == '*') {
        if (*pattern == *str || (*pattern == '.'&&*str != '\0')) {
            return matchCore(str + 1, pattern + 2) ||   //match once
                matchCore(str + 1, pattern) ||          //match more than once
                matchCore(str, pattern + 2);            //match zero
        }
        else {
            return matchCore(str, pattern + 2);         //match zero
        }
    }
    if (*str == *pattern || (*pattern == '.'&&*str != '\0')) {
        return matchCore(str + 1, pattern + 1);
    }
    return false;
}
bool match(char* str, char* pattern) {
    if (str == nullptr || pattern == nullptr) {
        return false;
    }
    return matchCore(str, pattern);
}

bool scanUnsignedInteger(const char** str) {
    const char* before = *str;
    while (**str != '\0'&&**str >= '0'&&**str <= '9') {
        ++(*str);
    }
    return *str > before;
}

bool scanInteger(const char** str) {
    if (**str == '+' || **str == '-') {
        ++(*str);
    }
    return scanUnsignedInteger(str);
}

bool isNumeric(const char* string) {
    if (string == nullptr) {
        return false;
    }
    bool numeric = scanInteger(&string);
    if (*string == '.') {
        ++string;
        numeric = scanUnsignedInteger(&string) || numeric;
    }
    if (*string == 'e' || *string == 'E') {
        ++string;
        numeric = numeric && scanInteger(&string);
    }
    return numeric && *string == '\0';
}


void reOrderArray(vector<int> &array) {
    if (array.empty()) {
        return;
    }
    for (int i = 0; i < array.size(); i++) {
        for (int j = array.size() - 1; j > i; j--) {
            if ((array[j] & 0x1) != 0 && (array[j - 1] & 0x1) == 0) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

void reOrderArray(int *pData, unsigned int length) {
    if (pData == nullptr || length == 0) {
        return;
    }
    int *pBegin = pData;
    int *pEnd = pData + length - 1;
    while (pBegin < pEnd) {
        // odd
        while (pBegin < pEnd && (*pBegin & 0x1) != 0) {
            pBegin++;
        }
        while (pBegin < pEnd && (*pBegin & 0x1) == 0) {
            pEnd--;
        }
        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (pListHead == nullptr || k == 0) {
        return nullptr;
    }
    ListNode* pNode = pListHead;
    int i = 0;
    ListNode* preNode = pNode;
    while (pNode != nullptr) {
        pNode = pNode->next;
        i++;
        if (i == k) {
            while (pNode != nullptr) {
                pNode = pNode->next;
                preNode = preNode->next;
            }
            return preNode;
        }
    }
    return nullptr;
}


ListNode* MeetingNode(ListNode* pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    ListNode* pSlow = pHead->next;
    if (pSlow == nullptr) {
        return nullptr;
    }
    ListNode* pFast = pSlow->next;
    while (pFast != nullptr || pSlow == nullptr) {
        if (pFast == pSlow) {
            return pSlow;
        }
        pSlow = pSlow->next;
        pFast = pFast->next;
        if (pFast != nullptr) {
            pFast = pFast->next;
        }

    }
    return nullptr;
}
ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    ListNode* meetingNode = MeetingNode(pHead);
    if (meetingNode == nullptr) {
        return nullptr;
    }
    ListNode* pNode = pHead;
    int count = 0;
    while (pNode != meetingNode) {
        pNode = pNode->next;
        count++;
    }
    ListNode* pSlow = pHead;
    ListNode* pFast = pHead;
    int i = 0;
    while (i < count) {
        pFast = pFast->next;
        i++;
    }
    while (pSlow != pFast) {
        pSlow = pSlow->next;
        pFast = pFast->next;
    }
    return pSlow;
}

ListNode* ReverseList(ListNode* pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    ListNode* pNode = pHead;
    ListNode* preNode = nullptr;
    ListNode* pReverseHead = nullptr;
    while (pNode != nullptr) {
        ListNode* pNext = pNode->next;
        if (pNext == nullptr) {
            pReverseHead = pNode;
        }
        pNode->next = preNode;
        preNode = pNode;
        pNode = pNext;
    }
    return pReverseHead;
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr && pHead2 == nullptr) {
        return nullptr;
    }
    if (pHead1 == nullptr && pHead2 != nullptr) {
        return pHead2;
    }
    if (pHead1 != nullptr && pHead2 == nullptr) {
        return pHead1;
    }
    ListNode* pNode1 = pHead1;
    ListNode* pNode2 = pHead2;
    ListNode* pMerge = nullptr;
    if (pNode1->val < pNode2->val) {
        pHead1 = pMerge = pNode1;
        pNode1 = pNode1->next;
    }
    else {
        pHead1 = pMerge = pNode2;
        pNode2 = pNode2->next;
    }
    while (pNode1 != nullptr && pNode2 != nullptr)
    {
        if (pNode1->val < pNode2->val) {
            pMerge->next = pNode1;
            pMerge = pNode1;
            pNode1 = pNode1->next;
        }
        else {
            pMerge->next = pNode2;
            pMerge = pNode2;
            pNode2 = pNode2->next;
        }
    }
    if (pNode1 != nullptr) {
        pMerge->next = pNode1;
    }
    if (pNode2 != nullptr) {
        pMerge->next = pNode2;
    }
    return pHead1;
}


ListNode* recursionMerge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr) {
        return pHead1;
    }
    else if (pHead2 == nullptr) {
        return pHead2;
    }
    ListNode* pMergeHead = nullptr;
    if (pHead1->val < pHead2->val) {
        pMergeHead = pHead1;
        pMergeHead->next = recursionMerge(pHead1->next, pHead2);
    }
    else
    {
        pMergeHead = pHead2;
        pMergeHead->next = recursionMerge(pHead1, pHead2->next);
    }
    return pMergeHead;
}

ListNode* ReverseMerge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr && pHead2 == nullptr) {
        return nullptr;
    }
    if (pHead1 == nullptr && pHead2 != nullptr) {
        return pHead2;
    }
    if (pHead1 != nullptr && pHead2 == nullptr) {
        return pHead1;
    }
    ListNode* pMerge = nullptr;
    ListNode* pNode1 = pHead1;
    ListNode* pNode2 = pHead2;
    ListNode* pNext = nullptr;
    while (pNode1 != nullptr && pNode2 != nullptr)
    {
        if (pNode1->val <= pNode2->val) {
            pNext = pNode1->next;
            pNode1->next = pMerge;
            pMerge = pNode1;
            pNode1 = pNext;
        }
        else {
            pNext = pNode2->next;
            pNode2->next = pMerge;
            pMerge = pNode2;
            pNode2 = pNext;
        }
    }
    while (pNode1 != nullptr) {
        pNext = pNode1->next;
        pNode1->next = pMerge;
        pMerge = pNode1;
        pNode1 = pNext;
    }
    while (pNode2 != nullptr) {
        pNext = pNode2->next;
        pNode2->next = pMerge;
        pMerge = pNode2;
        pNode2 = pNext;
    }
    return pMerge;
}


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {

    }
    TreeNode() :
        val(0), left(NULL), right(NULL) {

    }
};

bool EqualTree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if ((pRoot1->val - pRoot2->val)<1e-9 && (pRoot1->val - pRoot2->val)>-1e-9) {
        return true;
    }
    else {
        return false;
    }
}
bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot2 == nullptr) {
        return true;
    }
    if (pRoot1 == nullptr) {
        return false;
    }
    if (!EqualTree(pRoot1, pRoot2)) {
        return false;
    }
    return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    bool result = false;
    if (pRoot1 != nullptr&&pRoot2 != nullptr) {
        if (EqualTree(pRoot1, pRoot2)) {
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        }
        if (!result) {
            result = HasSubtree(pRoot1->left, pRoot2);
        }
        if (!result) {
            result = HasSubtree(pRoot1->right, pRoot2);
        }
    }
    return result;
}

void Mirror(TreeNode *pRoot) {
    TreeNode* pNode = nullptr;
    if (pRoot == nullptr) {
        return;
    }
    if (pRoot->left != nullptr || pRoot->right != nullptr) {
        pNode = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pNode;
    }
    if (pRoot->left != nullptr) {
        Mirror(pRoot->left);
    }
    if (pRoot->right != nullptr) {
        Mirror(pRoot->right);
    }
}


void Mirrorfor(TreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    stack<TreeNode*> stackNode;
    stackNode.push(pRoot);
    while (!stackNode.empty()) {
        TreeNode* tree = stackNode.top();
        stackNode.pop();
        if (tree->left != nullptr || tree->right != nullptr) {
            TreeNode* pNode = tree->left;
            tree->left = tree->right;
            tree->right = pNode;
        }
        if (tree->left != nullptr) {
            stackNode.push(tree->left);
        }
        if (tree->right != nullptr) {
            stackNode.push(tree->right);
        }
    }
}


void recursionPreorderTraversal(TreeNode* pRoot) {
    if (pRoot != nullptr) {
        cout << pRoot->val;
        recursionPreorderTraversal(pRoot->left);
        recursionPreorderTraversal(pRoot->right);
    }
}

void PreorderTraversal(TreeNode* pRoot) {
    stack<TreeNode*> stackNode;
    if (pRoot != nullptr) {
        stackNode.push(pRoot);
        while (!stackNode.empty())
        {
            TreeNode* tree = stackNode.top();
            stackNode.pop();
            cout << tree->val;
            if (tree->right != nullptr) {
                stackNode.push(tree->right);
            }
            if (tree->left != nullptr) {
                stackNode.push(tree->left);
            }
        }
    }
}

void recursionMidorderTraversal(TreeNode* pRoot) {
    if (pRoot != nullptr) {
        recursionMidorderTraversal(pRoot->left);
        cout << pRoot->val;
        recursionMidorderTraversal(pRoot->right);
    }
}

void MidorderTraversal(TreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    stack<TreeNode*> stackNode;
    TreeNode* curNode = pRoot;
    while (!stackNode.empty() || curNode != nullptr) {
        while (curNode != nullptr) {
            stackNode.push(curNode);
            curNode = curNode->left;
        }
        curNode = stackNode.top();
        cout << curNode->val;
        stackNode.pop();
        curNode = curNode->right;
    }
}

void recursionPostorderTraversal(TreeNode* pRoot) {
    if (pRoot != nullptr) {
        recursionPostorderTraversal(pRoot->left);
        recursionPostorderTraversal(pRoot->right);
        cout << pRoot->val;
    }
}

void PostorderTraversal(TreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    stack<TreeNode*> stackNode;
    TreeNode* curNode = pRoot;
    TreeNode* preNode = pRoot;
    while (curNode != nullptr || !stackNode.empty()) {
        while (curNode != nullptr) {
            stackNode.push(curNode);
            curNode = curNode->left;
        }
        curNode = stackNode.top();
        if (curNode->right == nullptr || curNode->right == preNode)
        {
            cout << curNode->val;
            preNode = curNode;
            stackNode.pop();
            curNode = nullptr;
        }
        else {
            curNode = curNode->right;
        }
    }
}


void PostorderTraversal1(TreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    stack<TreeNode*> stackNode;
    TreeNode* preNode = nullptr;
    stackNode.push(pRoot);
    TreeNode* curNode = nullptr;
    while (!stackNode.empty()) {
        curNode = stackNode.top();
        if ((curNode->left == nullptr && curNode->right == nullptr) || (preNode != nullptr && (preNode == curNode->left || preNode == curNode->right))) {
            cout << curNode->val;
            stackNode.pop();
            preNode = curNode;
        }
        else {
            if (curNode->right != nullptr) {
                stackNode.push(curNode->right);
            }
            if (curNode->left != nullptr) {
                stackNode.push(curNode->left);
            }
        }
    }
}



void breadthFirstOrder(TreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    queue<TreeNode*> queueNode;
    queueNode.push(pRoot);
    while (!queueNode.empty()) {
        TreeNode* curNode = queueNode.front();
        cout << curNode->val;
        queueNode.pop();
        if (curNode->left != nullptr) {
            queueNode.push(curNode->left);
        }
        if (curNode->right != nullptr) {
            queueNode.push(curNode->right);
        }
    }
}

TreeNode* construct(int* preOrder, int* midOrder, int length) {
    if (preOrder == nullptr || midOrder == nullptr) {
        return nullptr;
    }
    int rootKey = preOrder[0];
    TreeNode* root = new TreeNode(rootKey);
    if (length == 1 && *preOrder == *midOrder) {
        return root;
    }
    int* rootMidOrder = midOrder;
    int leftLength = 0;
    while (*rootMidOrder != rootKey && rootMidOrder <= (midOrder + length - 1)) {
        ++rootMidOrder;
        ++leftLength;
    }
    if (*rootMidOrder != rootKey) {
        return nullptr;
    }
    if (leftLength > 0) {
        root->left = construct(preOrder + 1, midOrder, leftLength);
    }
    if (leftLength - 1 > 0) {
        root->right = construct(preOrder + leftLength + 1, rootMidOrder + 1, length - leftLength - 1);
    }
    return root;
}

bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot1 == nullptr && pRoot2 == nullptr) {
        return true;
    }
    if (pRoot1 == nullptr || pRoot2 == nullptr) {
        return false;
    }
    if (pRoot1->val != pRoot2->val) {
        return false;
    }
    return isSymmetrical(pRoot1->left, pRoot2->right) &&
        isSymmetrical(pRoot1->right, pRoot2->left);
}

bool isSymmetrical(TreeNode* pRoot) {
    return isSymmetrical(pRoot, pRoot);
}


void printCirle(vector<vector<int> > numbers, int columns, int rows, int start) {
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;
    // left->right
    for (int i = start; i < endX; ++i) {
        cout << numbers[start][i];
    }
    // top->bottom
    if (start < endY) {
        for (int i = start + 1; i <= endY; ++i) {
            cout << numbers[i][endX];
        }
    }
    // right->left
    if (start < endX && start < endY) {
        for (int i = endX - 1; i >= start; --i) {
            cout << numbers[endY][i];
        }
    }
    // bottom->top
    if (start < endX && start < endY - 1) {
        for (int i = endY - 1; i > start + 1; --i) {
            cout << numbers[i][start];
        }
    }
}

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> result;
    if (matrix.empty()) {
        return result;
    }
    int rows = matrix.size();
    int columns = matrix[0].size();
    int start = 0;
    while (columns > start * 2 && rows > start * 2) {
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;
        // left->right
        for (int i = start; i <= endX; ++i) {
            result.push_back(matrix[start][i]);
        }
        // top->bottom
        if (start < endY) {
            for (int i = start + 1; i <= endY; ++i) {
                result.push_back(matrix[i][endX]);
            }
        }
        // right->left
        if (start < endX && start < endY) {
            for (int i = endX - 1; i >= start; --i) {
                result.push_back(matrix[endY][i]);
            }
        }
        // bottom->top
        if (start < endX && start < endY - 1) {
            for (int i = endY - 1; i >= start + 1; --i) {
                result.push_back(matrix[i][start]);
            }
        }
        ++start;
    }
    result.resize(rows*columns);
    return result;
}


class Min_stack {
    stack<int> data_stack;
    stack<int> min_stack;
    void push(int value) {
        data_stack.push(value);
        if (min_stack.size() == 0 || data_stack.top() < min_stack.top()) {
            min_stack.push(value);
        }
        else {
            min_stack.push(min_stack.top());
        }
    }
    void pop() {
        if (!data_stack.empty() && !min_stack.empty()) {
            data_stack.pop();
            min_stack.pop();
        }
    }
    int top() {
        if (!data_stack.empty()) {
            return data_stack.top();
        }
    }
    int min() {
        if (!min_stack.empty()) {
            return min_stack.top();
        }
    }
};


bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    bool bPossible = false;
    stack<int> data_stack;
    int k = 0;
    int i = 0;
    while (k < popV.size()) {
        while (data_stack.empty() || data_stack.top() != popV[k]) {
            if (i == pushV.size()) {
                break;
            }
            data_stack.push(pushV[i++]);
        }
        if (data_stack.top() != popV[k]) {
            break;
        }
        data_stack.pop();
        k++;
    }
    if (data_stack.empty()) {
        bPossible = true;
    }
    return bPossible;
}


vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    queue<TreeNode*> queueNode;
    queueNode.push(root);
    while (!queueNode.empty())
    {
        TreeNode* pNode = queueNode.front();
        queueNode.pop();
        result.push_back(pNode->val);
        if (pNode->left != nullptr) {
            queueNode.push(pNode->left);
        }
        if (pNode->right != nullptr) {
            queueNode.push(pNode->right);
        }
    }
    return result;
}


vector<vector<int> > Print1(TreeNode* pRoot) {
    vector<vector<int> > results;
    if (pRoot == nullptr) {
        return results;
    }
    queue<TreeNode*> queueNode;
    queueNode.push(pRoot);
    int nextLayer = 0;
    int toBePrinted = 1;
    vector<int> res;
    while (!queueNode.empty()) {
        TreeNode* pNode = queueNode.front();
        queueNode.pop();
        res.push_back(pNode->val);
        if (pNode->left != nullptr) {
            queueNode.push(pNode->left);
            ++nextLayer;
        }
        if (pNode->right != nullptr) {
            queueNode.push(pNode->right);
            ++nextLayer;
        }
        --toBePrinted;
        if (toBePrinted == 0) {
            results.push_back(res);
            res.resize(0);
            toBePrinted = nextLayer;
            nextLayer = 0;
        }
    }
    return results;
}

vector<vector<int> > Print2(TreeNode* pRoot) {
    vector<vector<int> > results;
    if (pRoot == nullptr) {
        return results;
    }
    queue<TreeNode*> queueNode;
    queueNode.push(pRoot);
    int flag = 1;
    int toBePrinted = 1;
    int nextLayer = 0;
    vector<int> res;
    while (!queueNode.empty()) {
        TreeNode* pNode = queueNode.front();
        queueNode.pop();
        if (flag % 2 != 0) {
            res.push_back(pNode->val);
        }
        else {
            res.insert(res.begin(), pNode->val);
        }
        if (pNode->left != nullptr) {
            queueNode.push(pNode->left);
            nextLayer++;
        }
        if (pNode->right != nullptr) {
            queueNode.push(pNode->right);
            nextLayer++;
        }
        --toBePrinted;
        if (toBePrinted == 0) {
            results.push_back(res);
            res.resize(0);
            toBePrinted = nextLayer;
            nextLayer = 0;
            ++flag;
        }
    }
    return results;
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty()) {
        return false;
    }
    int size = sequence.size();
    int i = 0;
    while (--size) {
        while (sequence[i++] < sequence[size]);
        while (sequence[i++] > sequence[size]);
        if (i < size) {
            return false;
        }
        i = 0;
    }
    return true;
}


void FindPath(TreeNode* pRoot, int expectNumber, vector<vector<int> >& path, vector<int>& trace) {
    trace.push_back(pRoot->val);
    bool isLeaf = pRoot->left == nullptr && pRoot->right == nullptr;
    if (expectNumber == pRoot->val && isLeaf) {
        path.push_back(trace);
    }
    if (pRoot->left) {
        FindPath(pRoot->left, expectNumber - pRoot->val, path, trace);
    }
    if (pRoot->right) {
        FindPath(pRoot->right, expectNumber - pRoot->val, path, trace);
    }
    trace.pop_back();
}


vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
    vector<vector<int> > results;
    if (root == nullptr) {
        return results;
    }
    vector<int> trace;
    FindPath(root, expectNumber, results, trace);
    return results;
}

vector<vector<int> > FindPath1(TreeNode* root, int expectNumber) {
    vector<vector<int> > results;
    if (root == nullptr) {
        return results;
    }
    stack<TreeNode*> s;
    s.push(root);
    int sum = 0;
    vector<int> curPath;
    TreeNode* cur = root;
    TreeNode* last = nullptr;
    while (!s.empty()) {
        if (cur == nullptr) {
            TreeNode* tmp = s.top();
            if (tmp->right != nullptr && tmp->right != last) {
                cur = tmp->right;
            }
            else {
                last = tmp;
                s.pop();
                curPath.pop_back();
                sum -= tmp->val;
            }
        }
        else {
            s.push(cur);
            sum += cur->val;
            curPath.push_back(cur->val);
            if (cur->left == nullptr && cur->right == nullptr && sum == expectNumber) {
                results.push_back(curPath);
            }
            cur = cur->left;
        }
    }
    return results;
}

struct RandomListNode{
    int label;
    struct RandomListNode* next;
    struct RandomListNode* random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};

void CloneNodes(RandomListNode* pHead) {
    RandomListNode* pNode = pHead;
    while (pNode != nullptr) {
        RandomListNode* pCloned = new RandomListNode(pNode->label);
        pCloned->next = pNode->next;
        pCloned->random = nullptr;
        pNode->next = pCloned;
        pNode = pCloned->next;
    }
}

void CloneRandom(RandomListNode* pHead) {
    RandomListNode* pNode = pHead;
    while (pNode != nullptr) {
        RandomListNode* pCloned = pNode->next;
        if (pNode->random != nullptr) {
            pCloned->random = pNode->random->next;
        }
        pNode = pCloned->next;
    }

}

RandomListNode* Clone(RandomListNode* pHead) {
    if (!pHead) {
        return nullptr;
    }
    RandomListNode* pNode = pHead;
    while (pNode) {
        RandomListNode* pCloned = new RandomListNode(pNode->label);
        pCloned->next = pNode->next;
        // pCloned->random = nullptr;
        pNode->next = pCloned;
        pNode = pCloned->next;
    }
    pNode = pHead;
    while (pNode) {
        RandomListNode* pCloned = pNode->next;
        if (pNode->random) {
            pCloned->random = pNode->random->next;
        }
        pNode = pCloned->next;
    }
    RandomListNode* pClonedHead = pHead->next;
    pNode = pHead;
    while (pNode) {
        RandomListNode* pCloned = pNode->next;
        pNode->next = pCloned->next;
        pNode = pNode->next;
        if (pNode) {
            pCloned->next = pNode->next;
        }
    }
    return pClonedHead;
    /*
    pNode = pHead;
    RandomListNode* pClonedHead = nullptr;
    RandomListNode* pClonedNode = nullptr;
    pClonedHead = pClonedNode = pNode->next;
    pNode->next = pClonedNode->next;
    pNode = pNode->next;
    while (pNode != nullptr) {
        pClonedNode->next = pNode->next;
        pClonedNode = pClonedNode->next;
        pNode->next = pClonedHead->next;
        pNode = pNode->next;
    }
    return pClonedHead;
    */
}


TreeNode* Convert(TreeNode* pRootOfTree)
{
    if (!pRootOfTree) {
        return nullptr;
    }
    stack<TreeNode*> stackNode;
    TreeNode* curNode = pRootOfTree;
    TreeNode* preNode = nullptr;
    TreeNode* pHead = nullptr;
    while (curNode || !stackNode.empty()) {
        while (curNode) {
            stackNode.push(curNode);
            curNode = curNode->left;
        }
        curNode = stackNode.top();
        if (!preNode) {
            pHead = curNode;
            preNode = curNode;
        }
        else {
            preNode->right = curNode;
            curNode->left = preNode;
            preNode = curNode;
        }
        stackNode.pop();
        curNode = curNode->right;
    }
    return pHead;
}


void Serialize(TreeNode* root, string& str) {
    if (!root) {
        str += '#';
        return;
    }
    string r = to_string(root->val);
    str += r;
    str += ',';
    Serialize(root->left, str);
    Serialize(root->right, str);
}

char* Serialize(TreeNode *root) {
    if (!root) {
        return NULL;
    }
    string str;
    Serialize(root, str);
    char * ret = new char[str.length() + 1];
    int i;
    for (i = 0; i < str.length(); i++) {
        ret[i] = str[i];
    }
    ret[i] = '\0';
    return ret;
}
TreeNode* Deserialize(char **str) {
    if (**str == '#') {
        ++(*str);
        return NULL;
    }
    int num = 0;
    while (**str != '\0' && **str != ',') {
        num = num * 10 + ((**str) - '0');
        ++(*str);
    }
    TreeNode* root = new TreeNode(num);
    if (**str == '\0') {
        return root;
    }
    else {
        (*str)++;
    }
    root->left = Deserialize(str);
    root->right = Deserialize(str);
    return root;
}
TreeNode* Deserialize(char *str) {
    if (str == nullptr) {
        return NULL;
    }
    TreeNode* root = Deserialize(&str);
    return root;
}

#include <set>
set<string> permutationSet;
vector<string> permutation;
bool isMatch(int arr[]) {
    if (!arr) {
        return false;
    }
    int r1 = arr[0] + arr[1] + arr[2] + arr[3];
    int r2 = arr[4] + arr[5] + arr[6] + arr[7];
    int r3 = arr[0] + arr[2] + arr[4] + arr[6];
    int r4 = arr[1] + arr[3] + arr[5] + arr[7];
    int r5 = arr[0] + arr[1] + arr[4] + arr[5];
    int r6 = arr[2] + arr[3] + arr[6] + arr[7];
    if (r1 == r2 && r3 == r4 && r5 == r6) {
        return true;
    }
    return false;
}
bool Permutation(int arr[], int start, int end) {
    if (arr == nullptr || sizeof(arr)/sizeof(arr[0]) <= 0) {
        return false;
    }
    if (start == end) {
        return false;
    }
    if (isMatch(arr)) {
        return true;
    }
    else {
        for (int p = start; p <= end; p++) {
            swap(arr[start], arr[p]);
            Permutation(arr, start + 1, end);
            swap(arr[start], arr[p]);
        }
    }
    return false;
}
void Permutation(string str, int nSize, int n) {
    if (n == nSize) {
        permutationSet.insert(str);
    }
    else {
        Permutation(str, nSize, n + 1);
        for (int i = n + 1; i < nSize; ++i) {
            if (str[n] != str[i]) {
                char tmp = str[n];
                str[n] = str[i];
                str[i] = tmp;
                Permutation(str, nSize, n + 1);
                tmp = str[n];
                str[n] = str[i];
                str[i] = tmp;
            }
        }
    }
}

vector<string> Permutation(string str) {
    if (str.size() != 0) {
        int nSize = str.size();
        Permutation(str, nSize, 0);
    }
    for (set<string>::iterator iter = permutationSet.begin(); iter != permutationSet.end(); iter++) {
        permutation.push_back(*iter);
    }
    return permutation;
}


void Combination(char* ptr, int n, vector<char> &results) {
    if (!ptr) {
        return;
    }
    if (n == 0) {
        vector<char>::iterator iter = results.begin();
        for (; iter != results.end(); ++iter) {
            cout << *iter;
        }
        cout << endl;
        return;
    }
    if (*ptr == '\0') {
        return;
    }
    results.push_back(*ptr);
    Combination(ptr + 1, n - 1, results);
    results.pop_back();
    Combination(ptr + 1, n, results);
}

void Combination(char* ptr) {
    if (!ptr) {
        return;
    }
    vector<char> result;
    int i, length = strlen(ptr);
    for (i = 1; i <= length; ++i) {
        Combination(ptr, i, result);
    }
}

int chart[8], sum = 0;
int check(int m) {
    int i;
    for (i = 0; i < m; i++) {
        if (chart[i] == chart[m] || abs(chart[i] - chart[m]) == (m - i)) {
            return 0;
        }
    }
    return 1;
}
void put(int n) {
    int j;
    for (j = 0; j < 8; ++j) {
        chart[n] = j;
        if (check(n)) {
            if (n == 7) {
                sum++;
            }
            else {
                put(n + 1);
            }
        }
    }
}

int MoreThanHalfNum_Solution(vector<int> numbers) {
    map<int, int> s;
    for (auto x : numbers) {
        if (!s.count(x)) {
            s.insert(make_pair(x, 1));
        }
        else {
            s.at(x)++;
        }
    }
    int len = numbers.size();
    for (auto ss : s) {
        if (ss.second > len / 2) {
            return ss.first;
        }
    }
    return 0;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> result;
    if (k>input.size()) {
        return result;
    }
    auto cmp = [](const int x, const int y) { return x > y; };
    make_heap(input.begin(), input.end(), cmp);
    for (int i = 0; i < k; i++) {
        pop_heap(input.begin(), input.end(), cmp);
        result.push_back(input.back());
        input.pop_back();
    }
    return result;
}

class problem1
{
    /*
    
    例如
    有效：(),(()),(()())
    无效：(,((),()())
    1.判断字符串是否是有效的括号组合
    例如：
    (()()(  长度为2
    2.求最长有效括号子串的长度
    */
    bool isValid(string str) {
        if (str.empty() || str.size() == 0) {
            return false;
        }
        int status = 0;
        for (int i = 0; i < str.size(); i++) {
            //if (str[i] != ')' && str[i] != '(') {
            //    return false;
            //}
            if (str[i] == ')' && --status < 0) {
                return false;
            }
            if (str[i] == '(') {
                status++;
            }
        }
        return status == 0;
    }

    int subStrLen(string str) {
        if (str.empty() || str.size() == 0) {
            return 0;
        }
        int* dp = new int[str.size()]();
        int pre = 0;
        int res = 0;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == ')') {
                pre = i - dp[i - 1] - 1;
                // ()(()())
                // 01234567
                // 02002048
                if (pre >= 0 && str[pre] == '(') {
                    dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
                }
            }
            res = max(res, dp[i]);
        }
        delete[] dp;
        return res;
    }
};

class problem2
{
    /*
    给定一个数组，值全为正数，返回累加和等于给定值k的最长子数组长度
    给定一个数组，值全为实数，范围累加和等于给定值k的最长子数组长度
    给定一个数组，值全为实数，范围累加和小于给定值k的最长子数组长度
    区别：子数组必须连续，子序列可以不连续
    最多允许多建立两个变量
    */
    int subStrLen1(float numbers[], int k) {
        int L = 0;
        int R = 0;
        int sum = 0;
        
    }


};

class problem3
{
    /*
    有一排正数，玩家A,B都可以看到，
    每位玩家只能从最左和最右选择一个数字，交替选择
    如：5,2,3,4
    A拿走5，B只能选择2,4
    A拿走4，B只能选择5,3
    求获胜者的分数。
    */
public:
    problem3();
    ~problem3();
    int win1(const int* arr, int length) {
        if (arr == nullptr || length == 0) {
            return 0;
        }
        return max(f(arr, 0, length - 1), s(arr, 0, length - 1));
    }
    int f(const int* arr, int i, int j) {
        if (i == j) {
            return arr[i];
        }
        return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));

    }
    int s(const int* arr, int i, int j) {
        if (i == j) {
            return 0;
        }
        return min(f(arr, i + 1, j), f(arr, i, j - 1));
    }

    int win2(const int arr[], int length) {
        if (arr == nullptr || length == 0) {
            return 0;
        }
        vector<vector<int> > f(length,vector<int>(length,0));
        vector<vector<int> > s(length,vector<int>(length,0));
        for (int j = 0; j < length; j++) {
            f[j][j] = arr[j];
            for (int i = j - 1; i >= 0; i--) {
                f[i][j] = max(arr[i] + s[i + 1][j], arr[j] + s[i][j - 1]);
                s[i][j] = min(arr[i] + f[i + 1][j], arr[j] + f[i][j - 1]);
            }
        }
        return max(f[0][length - 1], s[0][length - 1]);
    }

    int win3(const int arr[], int length) {
        if (arr == nullptr || length == 0) {
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += arr[i];
        }
        int scores = p(arr, 0, length - 1);
        return max(scores, sum - scores);
    }
    int p(const int arr[], int i, int j) {
        if (i == j) {
            return arr[i];
        }
        if (i + 1 == j) {
            return max(arr[i], arr[j]);
        }
        return max(arr[i] + min(p(arr, i + 2, j), p(arr, i + 1, j - 1)),
            arr[j] + min(p(arr, i, j - 2), p(arr, i + 1, j - 1)));
    }

    int win4(const int arr[], int length) {
        if (arr == nullptr || length == 0) {
            return 0;
        }
        vector<vector<int> > f(length, vector<int>(length, 0));
        for (int i = 0; i < length - 1; i++) {
            f[i][i] = arr[i];
            f[i][i + 1] = max(arr[i], arr[i + 1]);
        }
        f[length - 1][length - 1] = arr[length - 1];
        for (int k = 2; k < length; k++) {
            for (int j = k; j < length; j++) {
                int i = j - k;
                f[i][j] = max(arr[i] + min(f[i + 2][j], f[i + 1][j - 1]), arr[j] + min(f[i][j - 2], f[i + 1][j - 1]));
            }
        }
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += arr[i];
        }
        return max(f[0][length - 1], sum - f[0][length - 1]);
    }
};
bool check(vector<int> nums) {
	if (nums.empty()) {
		return false;
	}
	int n = nums.size();
	if (nums[0] > (nums[1] + nums[n - 1])) {
		return false;
	}
	if (nums[n - 1] > (nums[0] + nums[n - 2])) {
		return false;
	}
	for (int i = 1; i < n - 1; i++) {
		if (nums[i] >(nums[i - 1] + nums[i + 1])) {
			return false;
		}
	}
	return true;
}
bool Persort(vector<int> &nums, int start, int end) {
	if (nums.empty()) {
		return false;
	}
	if (start == end) {
		return false;
	}
	if (check(nums)) {
		return true;
	}
	else {
		for (int p = start; p < end; p++) {
			swap(nums[start], nums[p]);
			Persort(nums, start + 1, end);
			swap(nums[start], nums[p]);
		}
	}
	return false;
}

//int main() {
    //int s = 27;
    //std::stack<int> s1;
    //s1.push(24);
    //s1.push(33);
    //s1.push(22);
    //while (s1.size() != 0) {
    //    int x = s1.top();
    //    std::cout << x << ' ' << std::endl;
    //    s1.pop();

    //}
    //std::cout << "length:" << hailstone(s) << std::endl;
    //int array[] = {3,6,4,1,2,5,7,2,3,4,1,2};
    //HeapSort(array, 12);
    //ShellSort(array, 12);
    //BST *root;
    //CreateBST(&root, array, sizeof(array) / sizeof(int));
    //PrintResult(root);
    //SortAges(array, 12);
    //for (int i = 0; i < 12; i++) {
    //    std::cout << array[i] << " ";
    //}
    //std::cout << maxProduct2(18);
    //vector <vector<int> > matrix(4, vector<int>{1, 2, 3, 4});
    //printMatrix(matrix);
    //string line;
    //while (getline(cin,line)) {
    //    cout << line << endl;
    //    if (line.empty()) {
    //        break;
    //    }
    //}
    //int sum = 0;
    //int value = 0;
    //while (cin >> value) {
    //    sum += value;
    //}
    //cout << "sum = " << sum << endl;
    //while (cin >> line) {
    //    cout << line << endl;
    //    cout << (int)line.size() << endl;
    //}
    //string s("hello world!!!!");
    //decltype(s.size()) punct_cnt = 0;
    //for (auto c : s) {
    //    if (ispunct(c)) {
    //        ++punct_cnt;
    //    }
    //}
    //cout << punct_cnt
    //    << " punctuation characters in " << s << endl;

    //vector<int> pushV{ 1,2,3,4,5 };
    //vector<int> popV{ 4,5,3,2,1 };
    //IsPopOrder(pushV, popV);

    //int sum1 = 0;
    //int sum2 = 0;
    //float sum[100001] = { 0 };
    //float x;
    //float eps = 1e-14;
    //int M = 0;
    //int N = 10000;
    //cin >> x;
    //if (x < 1) {
    //    for (int i = 1; i <= 10000; i++) {
    //        if (abs(1.0 / i - x) < eps && i<N) {
    //            M = 1;
    //            N = i;
    //        }
    //    }
    //    cout << M << " " << N << endl; 
    //    system("pause");
    //    return 0;
    //}
    //int i = 1;
    //while (i <= 10000) {
    //    sum1 = floor(x)*i+1;
    //    sum2 = ceil(x)*i;
    //    for (int s = sum1; s <= sum2; s++) {
    //        if (abs(float(s) / i - x) < eps && i < N) {
    //            M = s;
    //            N = i;
    //        }
    //    }
    //    i++;
    //}
    //cout << M << " " << N << endl;
    //int ss = 0;
    //vector<string> lines;
    //while (ss < 6) {
    //    string line;
    //    cin >> line;
    //    lines.push_back(line);
    //    ss++;
    //}
    //ss = 0;
    //while (ss < 6) {
    //    int size = lines[ss].size();
    //    int size2 = lines[ss+1].size();
    //    int i = 0;
    //    int j = 0;
    //    int k = 0;
    //    bool pone = false;
    //    for (i = 0; i < size; i++) {
    //        pone = true;
    //        k = i;
    //        for (j = 0; j < size2; j++) {
    //            if (lines[ss+1][j] != lines[ss][k%size]) {
    //                pone = false;
    //                break;
    //            }
    //            k++;
    //        }
    //        if (pone) {
    //            break;
    //        }
    //    }
    //    ss += 2;
    //    if (pone) {
    //        cout << '1';
    //    }
    //    else {
    //        cout << '0';
    //    }
    //}
    //cout << endl;
    //TreeNode* pNode = new TreeNode(3);
    //char* s = Serialize(pNode);
    //cout << s;
 //   string s = "abcd";
 //   vector<string> lines = Permutation(s);
 //   for (auto s : lines) {
 //       cout << s << endl;
 //   }
 //   char* ss = "abcd";
 //   Combination(ss);
	//int array[8] = { 1,2,3,2,3,2,1,2 };
	//if (Permutation(array, 0, 7)) {
	//	cout << "ok" << endl;
	//}
	//int t,n;
	//vector<vector<int> > numbers;
	//cin >> t;
	//for (int i = 0; i < t; i++) {
	//	cin >> n;
	//	vector<int> tmp;
	//	for (int j = 0; j < n; j++) {
	//		int x;
	//		cin >> x;
	//		tmp.push_back(x);
	//	}
	//	numbers.push_back(tmp);
	//}
	//for (int i = 0; i < t; i++) {
	//	int end = numbers[i].size();
	//	bool res = Persort(numbers[i], 0, end);
	//	if (i == t - 1) {
	//		if (res) {
	//			cout << "YES" << endl;
	//		}
	//		else{
	//			cout << "NO" << endl;
	//		}
	//	}
	//	else {
	//		if (res) {
	//			cout << "YES" << endl;
	//		}
	//		else {
	//			cout << "NO" << endl;
	//		}
	//	}
	//	
	//}
//	int nums;
//	cin >> nums;
//	int p = 0;
//	string s;
//	vector<string> ss;
//	while (p<nums) {
//		cin >> s;
//		ss.push_back(s);
//		p++;
//	}
//	for (p = 0; p<ss.size(); p++) {
//		s = ss[p];
//		vector<char> result;
//		int num;
//		int i = 0;
//		while (i<s.size()) {
//			num = 0;
//			int nSize = 0;
//			vector<char> cs;
//			bool flag = false;
//			stack<char> kua;
//			while (s[i] == '(' || !kua.empty()) {
//				if (s[i++] == '(') {
//					kua.push(s[i]);
//				}
//				if (s[i] != ')') {
//					cs.push_back(s[i]);
//				}
//				else {
//					kua.pop();
//				}
//				i++;
//			}
//			while (s[i] >= '0' && s[i] <= '9') {
//				nSize++;
//				num = num * 10 + (s[i] - '0');
//				i++;
//			}
//			if (nSize > 0) {
//				i--;
//			}
//			if (num>0) {
//				if (flag) {
//					for (int j = 0; j<num; j++) {
//						for (int k = 0; k<cs.size(); k++) {
//							result.push_back(cs[k]);
//						}
//					}
//				}
//				else {
//					for (int j = 0; j<num-1; j++) {
//						result.push_back(s[i - nSize]);
//					}
//				}
//			}
//			else {
//				if (!flag) {
//					result.push_back(s[i]);
//				}
//			}
//			i++;
//		}
//		for (int k = 0; k<result.size(); k++) {
//			cout << result[k];
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include <algorithm>
//#include <iostream>
//#include <vector>>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	vector<int> o, e;
//	int tmp;
//	while (n--) {
//		cin >> tmp;
//		if (tmp % 2 == 0) {
//			e.push_back(tmp);
//		}
//		else {
//			o.push_back(tmp);
//		}
//	}
//	if (e.size() > 0 && o.size() > 0) {
//		sort(e.begin(), e.end());
//		sort(o.begin(), o.end());
//	}
//	int i = 0, j = 0;
//	vector<int> res;
//	while (i < e.size() && j < o.size()) {
//		if (e[i] < o[j]) {
//			res.push_back(e[i++]);
//		}
//		else {
//			res.push_back(o[j++]);
//		}
//	}
//	while (i < e.size()) {
//		res.push_back(e[i++]);
//	}
//	while (j < o.size()) {
//		res.push_back(o[j++]);
//	}
//	for (int i = 0; i < res.size() - 1; ++i) {
//		cout << res[i] << " ";
//	}
//	cout << res[res.size() - 1] << endl;
//	system("pause");
//	return 0;
//}


//int InversePairs(vector<int> array) {
//	if (array.empty())
//	{
//		return 0;
//	}
//	vector<int> copy(array);
//	int count = InversePairsCore(array, copy, 0, array.size() - 1);//数值过大求余
//	return count;
//}
//int InversePairsCore(vector<int> &array, vector<int> &copy, int low, int high)
//{
//	if (low == high)
//	{
//		copy[low] = array[low];
//		return 0;
//	}
//	int mid = (low + high) >> 1;
//	int leftCount = InversePairsCore(copy, array, low, mid);
//	int rightCount = InversePairsCore(copy, array, mid + 1, high);
//	int count = 0;
//	int i = mid;
//	int j = high;
//	int locCopy = high;
//	while (i >= low&&j>mid)
//	{
//		if (array[i]>array[j])
//		{
//			count += j - mid;
//			copy[locCopy--] = array[i--];
//			if (count >= 1000000007)//数值过大求余
//			{
//				count %= 1000000007;
//			}
//		}
//		else
//		{
//			copy[locCopy--] = array[j--];
//		}
//	}
//	for (; i >= low; i--)
//	{
//		copy[locCopy--] = array[i];
//	}
//	for (; j>mid; j--)
//	{
//		copy[locCopy--] = array[j];
//	}
//	return (leftCount + rightCount + count) % 1000000007;
//}


//bool cmp(int a, int b) {
//	string A = to_string(a) + to_string(b);
//	string B = to_string(b) + to_string(a);
//	return A < B;
//}
//
//int main() {
//	vector<int> numbers = { 321,32,3 };
//	sort(numbers.begin(), numbers.end(), cmp);
//	string res;
//	for (int i = 0; i < numbers.size(); i++) {
//		res += to_string(numbers[i]);
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}


//void reverseWord(string &str,int left, int right) {
//	while (left < right) {
//		int temp = str[left];
//		str[left] = str[right];
//		str[right] = temp;
//		left++;
//		right--;
//	}
//}
//
//int main() {
//	string str = "student. a am I student. a am I student. a am I";
//	if (str.size() <= 0) {
//		return 0;
//	}
//	int len = str.size();
//	reverseWord(str, 0, len - 1);
//	cout << str << endl;
//	string word;
//	int i = 0;
//	int left, right;
//	while(i < len) {
//		word = "";
//		left = i;
//		while (str[i] != ' ' && i < len) {
//			right = i++;
//		}
//		i++;
//		reverseWord(str, left, right);
//	}
//	cout << str << endl;
//	system("pause");
//	return 0;
//}

//ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//	if (!pHead1 || !pHead2) {
//		return nullptr;
//	}
//	if (pHead1->val == pHead2->val) {
//		return pHead1;
//	}
//	ListNode* pCom2 = pHead2;
//	while (pCom2->next) {
//		ListNode* node = pCom2;
//		ListNode* pCom1 = pHead1;
//		while (pCom1->next) {
//			if (node->val == pCom1->val) {
//				return node;
//			}
//			pCom1 = pCom1->next;
//		}
//		pCom2 = pCom2->next;
//	}
//	return nullptr;
//}

// O(n)
//int GetNumberOfK(vector<int> data, int k) {
//	int count = 0;
//	int flag = 0;
//	for (int i = 0; i < data.size(); i++) {
//		if (data[i] == k) {
//			count++;
//			flag = 1;
//		}
//		if (flag) {
//			if (data[i] != k) {
//				return count;
//			}
//		}
//	}
//}

//int getLastK(vector<int> array, int k, int start, int end) {
//	if (start > end) {
//		return -1;
//	}
//	int len = array.size();
//	int mid = (start + end) >> 1;
//	while (start <= end) {
//		if (array[mid] > k) {
//			end = mid - 1;
//		}
//		else if (array[mid] < k) {
//			start = mid + 1;
//		}
//		else if (mid + 1 < len && array[mid + 1] == k) {
//			start = mid + 1;
//		}
//		else {
//			return mid;
//		}
//		mid = (start + end) >> 1;
//	}
//}
//int getFirstK(vector<int> array, int k, int start, int end) {
//	if (start > end) {
//		return -1;
//	}
//	int len = array.size();
//	int mid = (start + end) >> 1;
//	while (start <= end) {
//		if (array[mid] > k) {
//			end = mid - 1;
//		}
//		else if (array[mid] < k) {
//			start = mid + 1;
//		}
//		else if (mid - 1 >= 0 && array[mid - 1] == k) {
//			end = mid - 1;
//		}
//		else {
//			return mid;
//		}
//		mid = (start + end) >> 1;
//	}
//}
//
//int GetNumOfK(vector<int> array, int k) {
//	int len = array.size();
//	if (array.empty()) {
//		return 0;
//	}
//	int firstK = getFirstK(array, k, 0, len - 1);
//	int lastK = getLastK(array, k, 0, len - 1);
//	if (firstK != -1 && lastK != -1) {
//		return lastK - firstK + 1;
//	}
//	return 0;
//}


//int GetNumOfK(vector<int> data, int k) {
//	auto resPair = equal_range(data.begin(), data.end(), k);
//	return resPair.second - resPair.first;
//}

//int TreeDepth(TreeNode* pRoot) {
//	if (!pRoot) {
//		return 0;
//	}
//	int left = TreeDepth(pRoot->left);
//	int right = TreeDepth(pRoot->right);
//	int depth = (left < right ? right + 1 : left + 1);
//	return depth;
//}


//int TreeDepth(TreeNode* pRoot) {
//	queue<TreeNode*> treeNodes;
//	if (!pRoot) {
//		return 0;
//	}
//	else {
//
//		treeNodes.push(pRoot);
//		int depth = 0;
//		int count = 0;
//		int nextCount = 1;
//		while (!treeNodes.empty()) {
//			TreeNode* node = treeNodes.front();
//			treeNodes.pop();
//			count++;
//			if (node->left) {
//				treeNodes.push(node->left);
//			}
//			if (node->right) {
//				treeNodes.push(node->right);
//			}
//			if (count == nextCount) {
//				nextCount = treeNodes.size();
//				count = 0;
//				depth++;
//			}
//		}
//		return depth;
//	}
//}

//void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//	if (data.size() < 2) {
//		return;
//	}
//	stack<int> s;
//	sort(data.begin(), data.end());
//	for (int i = 0; i < data.size(); i++) {
//		if (s.empty()) {
//			s.push(data[i]);
//		}
//		else {
//			if (s.top() == data[i]) {
//				s.pop();
//			}
//			else {
//				s.push(data[i]);
//			}
//		}
//	}
//	*num1 = s.top();
//	s.pop();
//	*num2 = s.top();
//}

//void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//	if (data.size() < 2) {
//		return;
//	}
//	map<int, int> hash;
//	for (int i = 0; i < data.size(); i++) {
//		hash[data[i]]++;
//	}
//	vector<int> v;
//	for (int i = 0; i < data.size(); i++) {
//		if (hash[data[i]] == 1) {
//			v.push_back(data[i]);
//		}
//	}
//	*num1 = v[0];
//	*num2 = v[1];
//}


//void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//	if (data.size() < 2) {
//		return;
//	}
//	set<int> nums;
//	set<int>::iterator iter;
//	for (int i = 0; i < data.size(); i++) {
//		if (nums.find(data[i]) == nums.end()) {
//			nums.insert(data[i]);
//		}
//		else {
//			iter = nums.find(data[i]);
//			nums.erase(iter);
//		}
//	}
//	iter = nums.begin();
//	*num1 = *iter;
//	*num2 = *(++iter);
//}

//bool IsBit(int num, int index) {
//	num = num >> index;
//	return (num & 1);
//}
//
//void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//	if (data.size() < 2) {
//		return;
//	}
//	int size = data.size();
//	int temp = data[0];
//	for (int i = 1; i < size; i++) {
//		temp ^= data[i];
//	}
//	if (temp == 0) {
//		return;
//	}
//	int index = 0;
//	while ((temp & 1) == 0) {
//		temp = temp >> 1;
//		++index;
//	}
//	*num1 = *num2 = 0;
//	for (int i = 0; i < size; i++) {
//		if (IsBit(data[i], index)) {
//			*num1 ^= data[i];
//		}
//		else {
//			*num2 ^= data[i];
//		}
//	}
//}
//
//
//int main() {
//	vector<int> nums = { 2,4,3,6,3,2,5,5 };
//	int num1, num2;
//	FindNumsAppearOnce(nums, &num1, &num2);
//	cout << num1 << " " << num2 << endl;
//	system("pause");
//	return 0;
//}

//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int> > box(n, vector<int>(m, 0));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> box[i][j];
//		}
//	}
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			int t = box[i][j] * 4 + 2;
//			if (i + 1 < n) {
//				t -= min(box[i][j], box[i + 1][j]);
//			}
//			if (i - 1 >= 0) {
//				t -= min(box[i][j], box[i - 1][j]);
//			}
//			if (j + 1 < m) {
//				t -= min(box[i][j], box[i][j + 1]);
//			}
//			if (j - 1 >= 0) {
//				t -= min(box[i][j], box[i][j - 1]);
//			}
//			count += t;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n, 0);
//	vector<int> b(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> b[i];
//	}
//	sort(a.begin(), a.end());
//	sort(b.begin(), b.end());	
//	vector<int> c(n, 0);
//	vector<int> hash(n, 0);
//	int j = 0;
//	for (int i = a.size() - 1; i >= 0; i--) {
//		int left = 0;
//		int right = b.size() - 1;
//		int find = m - 1 - a[i];
//		int mid = (left + right) >> 1;
//		while (left <= right) {
//			if (b[mid] > find) {
//				left = mid + 1;
//			}
//			if (b[mid] < find) {
//				right = mid - 1;
//			}
//			else {
//				break;
//			}
//			mid = (left + right) >> 1;
//		}
//		hash[mid] = 1;
//		c[j] = (b[mid] + a[i]) % m;
//	}
//	for (int i = 0; i < n; i++) {
//		cout << c[i] << " ";
//	}
//	system("pause");
//	return 0;
//}


//bool IsBalanced_Solution(TreeNode* pRoot) {
//	if (!pRoot) {
//		return true;
//	}
//	int left = TreeDepth(pRoot->left);
//	int right = TreeDepth(pRoot->right);
//	int diff = left - right;
//	if (diff > 1 || diff < -1) {
//		return false;
//	}
//	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//}


//vector<vector<int> > FindContinuousSequence(int sum) {
//	vector<vector<int> > res;
//	for (int i = 1; i <= sum/2; i++) {
//		vector<int> temp;
//		int s = 0;
//		int j = i;
//		while (s < sum) {
//			temp.push_back(j);
//			s += j;
//			j++;
//		}
//		if (s == sum) {
//			res.push_back(temp);
//		}
//	}
//	return res;
//}


//vector<int> FindNumbersWithSum(vector<int> array, int sum) {
//	vector<int> res(2, 0);
//	int left = 0;
//	int right = array.size() - 1;
//	int small, large;
//	int product = sum*sum;
//	while (left < right) {
//		small = array[left];
//		large = array[right];
//		if (small + large > sum) {
//			right--;
//		}
//		else if (small + large < sum) {
//			left++;
//		}
//		else {
//			if (small*large < product) {
//				res[0] = small;
//				res[1] = large;
//				product = small*large;
//			}
//			right--;
//		}
//	}
//	return res;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<map>
//using namespace std;
//bool hasSame(string a, string b) {
//	string S = a + b;
//	map<char, int> hash;
//	for (int i = 0; i < S.size(); i++) {
//		hash[S[i]]++;
//		if (hash[S[i]] > 1) {
//			return true;
//		}
//	}
//	return false;
//}
//
//int product(vector<string> s) {
//	vector<int> nums(s.size(), 0);
//	sort(s.begin(), s.end());
//	int product = 0;
//	for (int i = s.size() - 1; i >= 0; i--) {
//		for (int j = i - 1; j >= 0; j--) {
//			if (hasSame(s[i], s[j])) {
//				continue;
//			}
//			else {
//				if (s[i].size()*s[j].size() > product) {
//					product = s[i].size()*s[j].size();
//				}
//			}
//		}
//	}
//	return product;
//}
//
//int main() {
//	string A;
//	vector <string> B;
//	cin >> A;
//	int j = 1;
//	for (int i = 0; i<A.size(); i++) {
//		if (A[i] == '"') {
//			string word = "";
//			while (A[i + j] != '"') {
//				word += A[i + j];
//				j++;
//
//			}
//			B.push_back(word);
//			i += j;
//			j = 1;
//		}
//	}
//	int sum;
//	sum = product(B);
//	cout << sum << endl;
//	system("pause");
//	return 0;
//
//}


//int main() {
//	int y, m, d;
//	int days[12][2] = {
//		{ 0,0 },
//		{ 31,31 },
//		{ 60,59 },
//		{ 91,90 },
//		{ 121,120 },
//		{ 152,151 },
//		{ 182,181 },
//		{ 213,212 },
//		{ 244,243 },
//		{ 274,273 },
//		{ 305,304 },
//		{ 335,334 },
//	};
//	while (cin >> y >> m >> d) {
//		int day = 0;
//		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
//			day = days[m - 1][0] + d;
//		}
//		else {
//			day = days[m - 1][1] + d;
//		}
//		cout << day << endl;
//	}
//}


//int main() {
//	int n;
//	cin >> n;
//	int i = 0;
//	int j = 1;
//	while (i < n) {
//		i = i + j;
//		j++;
//	}
//	j--;
//	cout << j << endl;
//	system("pause");
//	return 0;
//}

//struct Point {
//	int x;
//	int y;
//};
//
//
//bool findpath(vector<vector<int> > box, int n, int m, Point st, Point en) {
//	stack<Point> s;
//	s.push(st);
//	Point p;
//	while (!s.empty()) {
//		Point cur = s.top();
//		if (cur.x = en.x && cur.y == en.y) {
//			return true;
//		}
//		if (cur.x + 1 < n&&box[cur.x + 1][cur.y] > 0) {
//			p.x = cur.x + 1;
//			p.y = cur.y;
//			s.push(p);
//		}
//		if (cur.x - 1 > 0 && box[cur.x - 1][cur.y] > 0) {
//			p.x = cur.x - 1;
//			p.y = cur.y;
//			s.push(p);
//		}
//		if (cur.y + 1 < m&&box[cur.x][cur.y + 1] > 0) {
//			p.x = cur.x;
//			p.y = cur.y + 1;
//			s.push(p);
//		}
//		if (cur.y - 1 > 0 && box[cur.x][cur.y - 1] > 0) {
//			p.x = cur.x;
//			p.y = cur.y - 1;
//			s.push(p);
//		}
//	}
//	return false;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	int i = 0;
//	vector<Point> start;
//	vector<Point> end;
//	vector<string> res;
//	vector<vector<vector<int> > > input;
//	vector<int> ms;
//	vector<int> ns;
//	while (i < t) {
//		int n, m;
//		cin >> n >> m;
//		ns.push_back(n);
//		ms.push_back(m);
//		vector<vector<int> > box(n, vector<int>(m, 0));
//		char x;
//		for (int j = 0; i < n; j++) {
//			for (int k = 0; k < m; k++) {
//				cin >> x;
//				if (x == '.') {
//					box[j][k] = 2;
//				}
//				if (x == 'X') {
//					box[j][k] = 1;
//				}
//			}
//		}
//		input.push_back(box);
//		Point a, b;
//		cin >> a.x >> a.y;
//		cin >> b.x >> b.y;
//		start.push_back(a);
//		end.push_back(b);
//	}
//	for (i = 0; i < t; i++) {
//		stack<Point> s;
//		Point st = start[i];
//		Point en = end[i];
//		bool result = findpath(input[i], ns[i], ms[i], st, en);
//		if (result) {
//			res.push_back("YES");
//		}
//		else {
//			res.push_back("NO");
//		}
//	}
//	for (auto str : res) {
//		cout << str << endl;
//	}
//
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
//int main() {
//	int n, k;
//	int mins = 150000;
//	int curmin = 0;
//	int index = 0;
//	cin >> n >> k;
//	vector<int> arr(n, 0);
//	for (int i = 0; i < n; ++i) {
//		cin >> arr[i];
//		if (i < k) {
//			curmin += arr[i];
//			mins = curmin;
//			continue;
//		}
//		curmin = curmin - arr[i - k] + arr[i];
//		if (mins > curmin) {
//			mins = curmin;
//			index = i - k + 1;
//		}
//	}
//	cout << index + 1 << endl;
//	return 0;
//}


//int main() {
//	long long n;
//	int m;
//	cin >> n >> m;
//	vector<long long> w(n, 0);
//	vector<long long> v(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> w[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	long long l = 0;
//	long long h = 1e12;
//	for (int i = 0; i < 100; ++i) {
//		long long mid = (l + h) >> 1;
//		long long sum = 0;
//		for (int j = 0; j < n; j++) {
//			if (mid > w[j]) {
//				long long tmp = (mid - w[j])*v[j];
//				sum += tmp;
//			}
//		}
//		if (sum <= m) {
//			l = mid;
//		}
//		else {
//			h = mid;
//		}
//	}
//	cout << l << endl;
//	return 0;
//}


//int LastRemaining_Solution(int n, int m)
//{
//	int k = 0, j = 0;
//	m %= n;
//	vector<int> hash(n, 1);
//	while (k <n - 2) {
//		j = 0;
//		for (int i = 0; i<=n - 1; i++) {
//			if (hash[i]) {
//				j++;
//			}
//			if (j == m-1) {
//				--hash[i];
//				k++;
//			}
//		}
//	}
//	for (int i = 0; i<n; i++) {
//		if (hash[i]) {
//			return i;
//		}
//	}
//}
//
//int main() {
//	int m = 5;
//	int n = 4;
//	int x = LastRemaining_Solution(n, m);
//	cout << x << endl;
//	system("pause");
//	return 0;
//}


//TreeNode* KthNode(TreeNode* pRoot, int k)
//{
//	int i = 0;
//	if (!pRoot) {
//		return nullptr;
//	}
//	stack<TreeNode*> nodes;
//	TreeNode* curNode = pRoot;
//	while (!nodes.empty() || curNode) {
//		while (curNode) {
//			nodes.push(curNode);
//			curNode = curNode->left;
//		}
//		curNode = nodes.top();
//		i++;
//		if (i == k) {
//			return curNode;
//		}
//		nodes.pop();
//		curNode = curNode->right;
//	}
//	return nullptr;
//}
//
//int main() {
//	vector<int> nums = { 5,3,7,2,4,6,8 };
//	TreeNode *head = new TreeNode(nums[0]);
//	queue<TreeNode*> Queue;
//	Queue.push(head);
//	int right = 0;
//	for (int i = 1; i < nums.size(); i++) {
//		TreeNode* cur = Queue.front();
//		TreeNode* tmp;
//		if (nums[i] == -1) {
//			tmp = nullptr;
//		}
//		else {
//			tmp = new TreeNode(nums[i]);
//		}
//		if (right == 1) {
//			Queue.pop();
//			cur->right = tmp;
//			if (tmp) {
//				Queue.push(tmp);
//			}
//			right = 0;
//		}
//		else
//		{
//			cur->left = tmp;
//			if (tmp) {
//				Queue.push(tmp);
//			}
//			right = 1;
//		}
//	}
//	TreeNode* res = KthNode(head, 3);
//	cout << res->val << endl;
//	system("pause");
//	return 0;
//
//}

int Sum(vector<int>array, int left, int right) {
	int sum = 0;
	for (int i = left; i <= right; i++) {
		sum += array[i];
	}
	return sum;
}
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	vector<int> Bl(n, 0);
//	vector<int> Br(n, 0);
//	Bl[0] = a[0];
//	Br[n - 1] = a[n - 1];
//	sort(a.begin(), a.end());
//	for (int i = 1; i < n; i++) {
//		Bl[i] = Bl[i - 1] + Bl[i - 1];
//	}
//	for (int i = n - 2; i >= 0; i--) {
//		Br[i] = Br[i + 1] + Br[i + 1];
//	}
//	for (int i = 0; i < n; i++) {
//		int left = Bl[i];
//		int right = Br[i+1];
//		if (left < right) {
//			if()
//		}
//	}
//	int right = n - 1;
//	for (int i = n - 1; i >= 0;i--){
//		if(B[i]<B[)
//	}
//
//}

//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//bool isRowValid(int row, vector<vector<char>>& board)//判断单独一行是否有效
//{
//	vector<char> temp;
//	for (int i = 0; i<board[0].size(); ++i)
//	{
//		if ('.' == board[row][i])
//			continue;
//		else
//		{
//			temp.push_back(board[row][i]);
//		}
//		for (int j = 0; j<temp.size() - 1; ++j)//判断最后push进的元素是否与前面的相同,因为是先push,后比较，所以要小于size（）-1
//		{
//			if (temp[j] == board[row][i])
//				return false;
//		}
//	}
//	return true;
//}
//
//bool isColumnValid(int column, vector<vector<char>>& board)//判断每一列是否有效
//{
//	vector<char> temp;
//	for (int i = 0; i<board[0].size(); ++i)
//	{
//		if (board[i][column] == '.')
//			continue;
//		else
//		{
//			temp.push_back(board[i][column]);
//		}
//		for (int j = 0; j<temp.size() - 1; ++j)//判断最后push进的元素是否与前面的相同,因为是先push,后比较，所以要小于size（）-1
//		{
//			if (temp[j] == board[i][column])
//				return false;
//		}
//	}
//	return true;
//}
//
////判断单独一个九宫格是否有效
//bool isNineValid(int row, int column, vector<vector<char>>& board)
//{
//	vector<char> temp;
//	for (int i = row; i<row + 3; ++i)
//	{
//		for (int j = column; j<column + 3; ++j)
//		{
//			if (board[i][j] == '.')
//				continue;
//			else
//			{
//				temp.push_back(board[i][j]);
//			}
//			for (int k = 0; k<temp.size() - 1; ++k)
//			{
//				if (temp[k] == board[i][j])
//					return false;
//			}
//		}
//	}
//	return true;
//}
//
//bool isValidSudoku(vector<vector<char>>& board) {
//	int len = 9;
//	//判断每一行是否满足
//	for (int i = 0; i<len; ++i)
//	{
//		if (isRowValid(i, board) == false)
//			return false;
//	}
//	//判断每一列是否满足
//	for (int i = 0; i<len; ++i)
//	{
//		if (isColumnValid(i, board) == false)
//			return false;
//	}
//	/*判断每一个格子是否满足，每一次找到一个九宫格的左上角位置，以次为基准开始判断*/
//	for (int i = 0; i<len; i += 3)
//	{
//		for (int j = 0; j<len; j += 3)
//		{
//			if (isNineValid(i, j, board) == false)
//				return false;
//		}
//	}
//	return true;
//}
//


//#include<iostream>
//#include<vector>
//using namespace std;
//bool isValidSudoku(vector<vector<char> > &board)
//{
//	if (board.empty() || board[0].empty())
//		return false;
//	int m = board.size(), n = board[0].size();
//	vector<vector<bool> > rowFlag(m, vector<bool>(n, false));
//	vector<vector<bool> > colFlag(m, vector<bool>(n, false));
//	vector<vector<bool> > cellFlag(m, vector<bool>(n, false));
//
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			if (board[i][j] >= '1' && board[i][j] <= '9')
//			{
//				int c = board[i][j] - '1';
//				if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c])
//					return false;
//
//				rowFlag[i][c] = true;
//				colFlag[c][j] = true;
//				cellFlag[3 * (i / 3) + j / 3][c] = true;
//			}
//		}
//	}
//	return true;
//}
//int main() {
//	vector<vector<char> > board(9, vector<char>(9, '.'));
//	
//	for (int i = 0; i < 9; i++) {
//		string s;
//		getline(cin, s);
//		for (int j = 0; j < s.size(); j++) {
//			board[i][j] = s[j];
//		}
//	}
//	if (isValidSudoku(board)) {
//		cout << "true" << endl;
//	}
//	else {
//		cout << "false" << endl;
//	}
//	system("pause");
//	return 0;
//}


//int maximumSwap(int num) {
//	int result;
//	string s = to_string(num);
//	int len = s.length();
//	vector<int> dp(len, -1);
//
//	int pos = len - 1;
//	for (int i = len - 1; i >= 0; i--) {
//		if (s[i]>s[pos]) {
//			pos = i;
//		}
//		dp[i] = pos;
//	}
//
//	for (int i = 0; i<len; i++) {
//		if (s[dp[i]] != s[i]) {
//			swap(s[i], s[dp[i]]);
//			break;
//		}
//	}
//
//	result = stoi(s);
//	return result;
//
//}

//int Move[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
////void dfs(vector<vector<char> >& grid, int i, int j) {
////	grid[i][j] == '0';
////	int nr = grid.size();
////	int nc = grid[0].size();
////	if (i-1>=0)
////	return;
////}
//void dfs(vector<vector<char>>& grid, int r, int c) {
//	int nr = grid.size();
//	int nc = grid[0].size();
//
//	grid[r][c] = '0';
//	if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
//	if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
//	if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
//	if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
//}
//
//int numIslands(vector<vector<char> >& grid) {
//	int count = 0;
//	if (grid.empty()) {
//		return count;
//	}
//	for (int i = 0; i<grid.size(); i++) {
//		for (int j = 0; j<grid[0].size(); j++) {
//			if (grid[i][j] == '1') {
//				dfs(grid, i, j);
//				count++;
//			}
//		}
//	}
//	return count;
//}
//int main() {
//	vector<vector<char> > m = { {'1','1','0','0','0'},
//	{'1','1','0','1','0'},
//	{'1','1','0','0','0'},
//	{'0','0','0','0','0'} };
//	cout << numIslands(m) << endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main() {
//	int n;
//	cin >> hex >> n;
//	vector<int> data(n - 1);
//	string c[16] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
//	for (int i = 0; i < n-1; i++) {
//		cin >> hex >> data[i];
//	}
//	vector<string> res;
//	for (int i = 0; i < n - 1; i++) {
//		if (data[i] == 10) {
//			res.push_back("12");
//			res.push_back("34");
//		}
//		else if (data[i] == 11) {
//			res.push_back("AB");
//			res.push_back("CD");
//		}
//		else {
//			int num1 = data[i] / 16;
//			int num2 = data[i] % 16;
//			if (num1 == 0) {
//				res.push_back(c[num2]);
//			}
//			else {
//				res.push_back(c[num1] + c[num2]);
//			}
//		}
//	}
//	int len = res.size() + 1;
//	cout << len << " ";
//	for (int i = 0; i < res.size() - 1; i++) {
//		cout << res[i] << " ";
//	}
//	cout << res[res.size() - 1] << endl;
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int sum1 = 0, sum2 = 0;
//	for (int i = n; i < m; i++)
//	{
//		int t = sqrt(i);
//		bool flag = true;
//		for (int j = 2; j <= t; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (flag)
//		{
//			sum1 += (i % 100) / 10;
//			sum2 += i % 10;
//		}
//	}
//	int res = sum1 < sum2 ? sum1 : sum2;
//	cout << res << endl;
//	return 0;
//}


//int main() {
//	string first;
//	int n;
//	cin >> first;
//	cin >> n;
//	vector<string> input;
//	vector<vector<string> > human;
//	for (int i = 0; i < n; i++) {
//		string tmp;
//		cin >> tmp;
//		input.push_back(tmp);
//	}
//	for (int i = 0; i < n; i++) {
//		vector<string> h;
//		for (int j = 0; j < input[i].size(); j++) {
//			string word;
//			while (input[i][j] != ',' && j<input[i].size()) {
//				word += input[i][j++];
//			}
//			h.push_back(word);
//		}
//		human.push_back(h);
//	}
//	map<string, int> hash;
//	for (int i = 0; i < human.size(); i++) {
//		for (int j = 0; j < human[i].size(); j++) {
//			hash[human[i][j]]++;
//		}
//	}
//	int num = hash.size();
//	vector<vector<int> > flag(n, vector<int>(num, 0));
//	for (int i = 0; i < num; i++) {
//		cout << flag[i] << endl;
//	}
//	//for (int i = 0; i < n; i++) {
//	//	for (int j = 0; j < num; j++) {
//	//	}
//	//}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <set>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int main()
//{
//	string start;
//	getline(cin, start);
//	int m;
//	scanf("%d\n", &m);
//	vector<set<string>> group(m);
//	for (int i = 0; i < m; i++)
//	{
//		string str;
//		getline(cin, str);
//		int id = str.find(",");
//		set<string> tmp;
//		while (id != str.npos)
//		{
//			string s = str.substr(0, id);
//			tmp.insert(s);
//			str = str.substr(id + 1);
//			id = str.find(",");
//		}
//		tmp.insert(str);
//		group[i] = tmp;
//	}
//	queue<string> names;
//	set<string> hasGet;
//	hasGet.insert(start);
//	names.push(start);
//	vector<int> flag(m, 0);
//	int count = 0;
//	while (!names.empty() && count < group.size())
//	{
//		string t = names.front();
//		names.pop();
//		for (int i = 0; i < group.size(); i++)
//		{
//			if (flag[i] == 1)
//				continue;;
//			if (group[i].find(t) != group[i].end())
//			{
//				for (auto iter = group[i].begin(); iter != group[i].end(); iter++)
//				{
//					if (hasGet.find(*iter) == hasGet.end())
//					{
//						names.push(*iter);
//						hasGet.insert(*iter);
//					}
//				}
//				count++;
//				flag[i] = 1;
//			}
//		}
//	}
//	cout << hasGet.size() << endl;
//	system("pause");
//	return 0;
//}


struct People
{
	string name;
	int age;
	bool operator <(const People p) const  //运算符重载 
	{
		return age<p.age;       //按照年龄由小到大进行排序 
	}
};

string getstr(vector<string> strs) {
	string res;
	map<string, int> hash;
	return res;

}


//#include <iostream>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//vector<string> helper(vector<string> tmp, int index)
//{
//	if (tmp.size() == 1)
//		return tmp; 
//
//	vector<string> result;
//	vector<int> flag(tmp.size(), 0);
//	for (int i = 'z'; i >= 'a'; i--)
//	{
//		vector<string> t;
//		for (int j = 0; j < tmp.size(); j++)
//		{
//			if (flag[j] == 1)
//				continue;
//			if (tmp[j].size() <= index)
//			{
//				result.push_back(tmp[j]);
//				flag[j] = 1;
//				continue;
//			}
//			if (tmp[j][index] == i)
//			{
//				t.push_back(tmp[j]);
//				flag[j] = 1;
//			}
//		}
//		if (t.empty())
//			continue;
//		vector<string> res = helper(t, index + 1);
//		for (int j = 0; j < res.size(); j++)
//			result.push_back(res[j]);
//	}
//	return result;
//}
//int main()
//{
//	string s;
//	getline(cin, s);
//	int id = s.find(",");
//	vector<string> tmp;
//	while (id != s.npos)
//	{
//		string str = s.substr(0, id);
//		tmp.push_back(str);
//		s = s.substr(id + 1);
//		id = s.find(",");
//	}
//	tmp.push_back(s);
//	vector<string> res = helper(tmp, 0);
//	for (int i = 0; i < res.size() - 1; i++)
//		cout << res[i] << ",";
//	cout << res[res.size() - 1] << endl;
//	system("pause");
//	return 0;
//}

//
//#include<iostream>
//#include<map>
//#include<string>
//#include<vector>
//using namespace std;
//vector<string> res;
//void dfs(vector<string> &input, int i) {
//
//}
//int main() {
//	string str;
//	cin >> str;
//	
//	vector<vector<string> > strs(26);
//	vector<string> res;
//	for (int k = 0; k < 4; k++) {
//		map<string, int> hash;
//		for (int i = 0; i < str.size(); i++) {
//			string word;
//			while (str[i] != ',' && i < str.size()) {
//				word += str[i++];
//			}
//			if (word[0] == ' ') {
//				continue;
//			}
//			hash[word]++;
//			strs[word[k] - 'a'].push_back(word);
//		}
//		vector<string> mid;
//		for (auto iter = hash.begin(); iter != hash.end(); iter++) {
//			for (int i = 0; i < iter->second; i++) {
//				mid.push_back(iter->first);
//			}
//		}
//
//
//	}
//	for (int i = 0; i < str.size(); i++) {
//		string word;
//		while (str[i] != ','&&i < str.size()) {
//			word += str[i++];
//		}
//		if (word[0] == ' ') {
//			continue;
//		}
//		hash[word]++;
//		strs[word[0] - 'a'].push_back(word);
//	}
//	vector<string> mid;
//	for (auto iter = hash.begin(); iter != hash.end(); iter++) {
//		for (int i = 0; i < iter->second; i++) {
//			mid.push_back(iter->first);
//		}
//	}
//	for (int i = 0; i < mid.size(); i++) {
//		cout << mid[i] << ",";
//	}
//	for (int i = 0; i < str.size(); i++) {
//		string word;
//		while (str[i] != ','&&i < str.size()) {
//			word += str[i++];
//		}
//		if (word[0] == ' ') {
//			continue;
//		}
//		hash[word]++;
//		strs[word[1] - 'a'].push_back(word);
//	}
//	vector<string> mid2;
//	for (auto iter = hash.rbegin(); iter != hash.rend(); iter++) {
//		for (int i = 0; i < iter->second; i++) {
//			mid.push_back(iter->first);
//		}
//	}
//	for (int i = 0; i < mid2.size(); i++) {
//		cout << mid2[i] << ",";
//	}
//
//	system("pause");
//	return 0;
//
//}


//int main() {
//	int n;
//	cin >> n;
//	vector<string> res(n);
//	for (int i = 0; i < n; i++) {
//		cin >> res[i];
//	}
//	
//}

//class Solution {
//private:
//	void dfs(vector<vector<char>>& grid, int r, int c) {
//		int nr = grid.size();
//		int nc = grid[0].size();
//
//		grid[r][c] = '0';
//		if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
//		if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
//		if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
//		if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
//	}
//
//public:
//	int numIslands(vector<vector<char>>& grid) {
//		int nr = grid.size();
//		if (!nr) return 0;
//		int nc = grid[0].size();
//
//		int num_islands = 0;
//		for (int r = 0; r < nr; ++r) {
//			for (int c = 0; c < nc; ++c) {
//				if (grid[r][c] == '1') {
//					++num_islands;
//					dfs(grid, r, c);
//				}
//			}
//		}
//
//		return num_islands;
//	}
//};
//
//
//class Solution {
//public:
//	int numIslands(vector<vector<char>>& grid) {
//		int nr = grid.size();
//		if (!nr) return 0;
//		int nc = grid[0].size();
//
//		int num_islands = 0;
//		for (int r = 0; r < nr; ++r) {
//			for (int c = 0; c < nc; ++c) {
//				if (grid[r][c] == '1') {
//					++num_islands;
//					grid[r][c] = '0'; // mark as visited
//					queue<pair<int, int>> neiors;
//					neiors.push({ r, c });
//					while (!neiors.empty()) {
//						auto rc = neiors.front();
//						neiors.pop();
//						int row = rc.first, col = rc.second;
//						if (row - 1 >= 0 && grid[row - 1][col] == '1') {
//							neiors.push({ row - 1, col }); grid[row - 1][col] = '0';
//						}
//						if (row + 1 < nr && grid[row + 1][col] == '1') {
//							neiors.push({ row + 1, col }); grid[row + 1][col] = '0';
//						}
//						if (col - 1 >= 0 && grid[row][col - 1] == '1') {
//							neiors.push({ row, col - 1 }); grid[row][col - 1] = '0';
//						}
//						if (col + 1 < nc && grid[row][col + 1] == '1') {
//							neiors.push({ row, col + 1 }); grid[row][col + 1] = '0';
//						}
//					}
//				}
//			}
//		}
//
//		return num_islands;
//	}
//};
//


#include<algorithm>
#include<functional>
#include<vector>
vector<int> Min;
vector<int> Max;
void Insert(int num) {
	if (((Min.size() + Max.size()) & 1) == 0) {
		if (Max.size() > 0 && num < Max[0]) {
			Max.push_back(num);
			push_heap(Max.begin(), Max.end(),less<int>());
			num = Max[0];
			pop_heap(Max.begin(), Max.end(), less<int>());
			Max.pop_back();
		}
		Min.push_back(num);
		push_heap(Min.begin(), Min.end(), greater<int>());
	}
	else {
		if (Min.size() > 0 && num > Min[0]) {
			Min.push_back(num);
			push_heap(Min.begin(), Min.end(), greater<int>());
			num = Min[0];
			pop_heap(Min.begin(), Min.end(), greater<int>());
			Min.pop_back();
		}
		Max.push_back(num);
		push_heap(Max.begin(), Max.end(), less<int>());
	}
}
int GetMedian() {
	int size = Min.size() + Max.size();
	if (size == 0) {
		return -1;
	}
	int median = 0;
	if ((size & 1) == 0) {
		median = (Max[0] + Min[0]) / 2;
	}
	else {
		median = Min[0];
	}
	return median;
}


//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int> > v(n, vector<int>(m, 0));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> v[i][j];
//		}
//	}
//	vector<vector<int> > dp(n, vector<int>(m, 0));
//	dp[n - 1][m - 1] = max(1, 1 - v[n - 1][m - 1]);
//	for (int i = n - 2; i >= 0; i--) {
//		dp[i][m - 1] = max(1, dp[i + 1][m - 1] - v[i][m - 1]);
//	}
//	for (int j = m - 2; j >= 0; j--) {
//		dp[n - 1][j] = max(1, dp[n - 1][j + 1] - v[n - 1][j]);
//	}
//	for (int i = n - 2; i >= 0; i--) {
//		for (int j = m - 2; j >= 0; j--) {
//			dp[i][j] = max(1, min(dp[i][j + 1], dp[i + 1][j]) - v[i][j]);
//		}
//	}
//	
//	cout<< dp[0][0];
//	system("pause");
//	return 0;
//
//}

//int main() {
//	int n;
//	cin >> n;
//	vector<int> v(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	int c;
//	cin >> c;
//	vector<int> res(c + 1, -1);
//	res[0] = 0;
//	for (int i = 1; i <= c; i++) {
//		for (int j = 0; j < n; j++) {
//			int tmp = i - v[j];
//			if (tmp < 0) {
//				continue;
//			}
//			if (res[tmp] == -1) {
//				continue;
//			}
//			if (res[i] == -1) {
//				res[i] = res[tmp] + 1;
//			}
//			else {
//				res[i] = min(res[i], res[tmp] + 1);
//			}
//		}
//	}
//	cout << res[c] << endl;
//	system("pause");
//	return 0;
//}

//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n, 0);
//	vector<int> b(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> b[i];
//	}
//	int sum = 0;
//	int i = 0, j = 0;
//	while (i < n&&j < n) {
//		if (b[j] && a[i]) {
//			sum += j - i;
//			b[j]--;
//			a[i]--;
//		}
//		if (b[j] == 0) {
//			j++;
//		}
//		if (a[i] == 0) {
//			i++;
//		}
//	}
//	cout << sum << endl;
//	system("pause");
//	return 0;
//
//}

//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	int count[4] = { 0,0,0,0 };
//	for (int i = 0; i < n; i++) {
//		if (a[i] % 3 == 0) {
//			count[3]++;
//		}
//		if (a[i] % 3 == 1) {
//			count[1]++;
//		}
//		if (a[i] % 3 == 2) {
//			count[2]++;
//		}
//	}
//	int Min = min(count[1], count[2]);
//	int res = 0;
//	if (k <= Min) {
//		res = k + count[3];
//	}
//	else {
//		res = count[3] + Min;
//		int tmp = k - Min;
//		if (count[1] - Min > 0) {
//			count[1] -= Min;
//			while ((count[1] - 3 >= 0) && (tmp - 2 >= 0)) {
//				res++;
//				tmp -= 2;
//				count[1] -= 3;
//			}
//		}
//		if (count[2] - Min > 0) {
//			count[2] -= Min;
//			while ((count[2] - 3 >= 0) && (tmp - 2 >= 0)) {
//				res++;
//				tmp -= 2;
//				count[2] -= 3;
//			}
//		}
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}


//int main() {
//	int n, m, s, d;
//	cin >> n >> m >> s >> d;
//	vector<long> value(n+1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> value[i];
//	}
//	vector<vector<long> > cost(m+1,vector<long>(m+1,1e13));
//	vector<vector<long> > q(m+1, vector<long>(m+1, 0));
//	for (int i = 1; i <=m; i++) {
//		int x, y;
//		cin >> x >> y;
//		cin >> q[x][y];
//		cost[x][y] = q[x][y] * 1e6 - value[y];
//	}
//	int start = s;
//	int end = d;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			for (int k = 1; k <= n; k++) {
//				if (cost[i][k] + cost[k][j] < cost[i][j]) {
//					cost[i][j] = cost[i][k] + cost[k][j];
//				}
//			}
//		}
//	}
//	cout << cost[start][end] << endl;
//	system("pause");
//	return 0;
//}
//


//#include<iostream>
//#include<string>
//
//int getMax(string s, int &maxlen) {
//	int i = 1, pos = 0, maxpos = 0;
//	int L = 1;
//	maxlen = 0;
//	while (s[i]) {
//		if (s[i] == s[i - 1]) {
//			++L;
//		}
//		else{
//			if (L > maxlen) {
//				maxlen = L;
//				maxpos = pos;
//				
//			}
//			pos = i;
//			L = 1;
//		}
//		++i;
//	}
//	return maxpos;
//}
//
//int main() {
//	char s[] = "ddddddd1112236000000000543";
//	int len, pos;
//	pos = getMax(s, len);
//	printf("pos = %d,len = %d\n", pos, len);
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Solution
//{
//public:
//	//Insert one char from stringstream
//	Solution():index(0) {
//		memset(occurence, -1, sizeof(occurence));
//	}
//	void Insert(char ch)
//	{
//		if (occurence[ch] == -1) {
//			occurence[ch] = index;
//		}
//		else if (occurence[ch] >= 0) {
//			occurence[ch] = -2;
//		}
//		index++;
//	}
//	//return the first appearence once char in current stringstream
//	char FirstAppearingOnce()
//	{
//		char ch = '#';
//		int minIndex = INT_MAX;
//		for (int i = 0; i<256; i++) {
//			if (occurence[i] >= 0 && occurence[i]<minIndex) {
//				ch = (char)i;
//				minIndex = occurence[i];
//			}
//		}
//		return ch;
//	}
//private:
//	int index;
//	int occurence[256];
//};
//
//int main() {
//	char a;
//	Solution s;
//	while (cin >> a) {
//		s.Insert(a);
//		char ch = s.FirstAppearingOnce();
//		cout << ch << endl;
//	}
//	return 0;
//}

//#include<map>
//#include<iostream>
//#include<sstream>
//using namespace std;
//int main() {
//	map<char, int> hash;
//	string s;
//	cin >> s;
//	int i = 0;
//	while (s[i]) {
//		hash[s[i++]]++;
//	}
//	map<char, int>::iterator iter = hash.begin();
//	string res;
//	stringstream ss;
//	for (; iter != hash.end(); iter++) {
//		if (iter->second > 0) {
//			res.push_back(iter->first);
//			string tmp;
//			ss << iter->second;
//			ss >> tmp;
//			ss.clear();
//			res.append(tmp);
//		}
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	int n = s1.size() + 1;
//	int m = s2.size() + 1;
//	vector<vector<int> > dp(n, vector<int>(m, 0));
//	for (int i = 0; i < n; i++) {
//		dp[i][0] = i;
//	}
//	for (int j = 0; j < m; j++) {
//		dp[0][j] = j;
//	}
//	for (int i = 1; i < n; i++) {
//		for (int j = 1; j < m; j++) {
//			if (s1[i - 1] == s2[j - 1]) {
//				dp[i][j] = dp[i - 1][j - 1];
//			}
//			else {
//				int tmp = min(dp[i - 1][j], dp[i][j - 1]);
//				dp[i][j] = min(tmp, dp[i - 1][j - 1]) + 1;
//			}
//		}
//	}
//	cout << dp[n-1][m-1] << endl;
//	system("pause");
//	return 0;
//}


void print(vector<vector<int> > &grid) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}



//#include<iostream>
//#include<vector>
//using namespace std;
//int count(vector<vector<int> > &grid) {
//	int num = 0;
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (grid[i][j] != 0) {
//				num++;
//			}
//		}
//	}
//	return num;
//}
//void dfs(vector<vector<int> > &grid, int r, int c, int &tmp) {
//	grid[r][c] = 0;
//	if (r - 1 >= 0 && grid[r - 1][c] == tmp) dfs(grid, r - 1, c, tmp);
//	if (r + 1 < 5 && grid[r + 1][c] == tmp) dfs(grid, r + 1, c, tmp);
//	if (c - 1 >= 0 && grid[r][c - 1] == tmp) dfs(grid, r, c - 1, tmp);
//	if (c + 1 < 5 && grid[r][c + 1] == tmp) dfs(grid, r, c + 1, tmp);
//}
//void adjust(vector<vector<int> > &grid) {
//	for (int j = 0; j < 5; j++) {
//		vector<int> res;
//		for (int i = 4; i >= 0; i--) {
//			if (grid[i][j] != 0) {
//				res.push_back(grid[i][j]);
//			}
//		}
//		int k = 4;
//		int n = res.size();
//		int l = 0;
//		while (l < n) {
//			grid[k][j] = res[l];
//			l++;
//			k--;
//		}
//		while (k >= 0) {
//			grid[k][j] = 0;
//			k--;
//		}
//	}
//}
//
//int main() {
//	vector<vector<int> > grid(5, vector<int>(5, 0));
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			cin >> grid[i][j];
//		}
//	}
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (grid[i][j] == 3) {
//				if (i - 1 >= 0) {
//					int tmp = grid[i - 1][j];
//					if (tmp != 0 && tmp != 3)
//						dfs(grid, i - 1, j, tmp);
//					adjust(grid);
//				}
//				if (i + 1 < 5) {
//					int tmp = grid[i + 1][j];
//					if (tmp != 0 && tmp != 3)
//						dfs(grid, i + 1, j, tmp);
//					adjust(grid);
//				}
//				if (j - 1 >= 0) {
//					int tmp = grid[i][j - 1];
//					if (tmp != 0 && tmp != 3)
//						dfs(grid, i, j - 1, tmp);
//					adjust(grid);
//				}
//				if (j + 1 < 5) {
//					int tmp = grid[i][j + 1];
//					if (tmp != 0 && tmp != 3)
//						dfs(grid, i, j + 1, tmp);
//					adjust(grid);
//				}
//			}
//
//		}
//	}
//	int res = count(grid);
//	cout << res << endl;
//	print(grid);
//	system("pause");
//	return 0;
//}

//int main() {
//	int n;
//	cin >> n;
//	vector<long> w(n);
//	long sum = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> w[i];
//		sum += w[i];
//	}
//	int count = 0;
//	while (sum != 0) {
//		int t = log(sum) / log(2);
//		sum -= pow(2, t);
//		count++;
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}

// range heap example
//#include <iostream>
//#include <algorithm>
//#include <functional>
//#include <vector>
//using namespace std;
//
//int main() {
//	int myints[] = { 10,20,30,5,15 };
//	vector<int> v(myints, myints + 5);
//
//	make_heap(v.begin(), v.end(),greater<int>());
//	cout << "initial max heap   : " << v.front() << endl;
//
//	pop_heap(v.begin(), v.end(), greater<int>()); v.pop_back();
//	cout << "max heap after pop : " << v.front() << endl;
//
//	v.push_back(99); push_heap(v.begin(), v.end(), greater<int>());
//	cout << "max heap after push: " << v.front() << endl;
//	for (unsigned i = 0; i < v.size(); i++) cout << " " << v[i];
//
//	cout << endl;
//	sort_heap(v.begin(), v.end(), greater<int>());
//
//	cout << "final sorted range :";
//	for (unsigned i = 0; i < v.size(); i++) cout << " " << v[i];
//
//	cout << endl;
//	system("pause");
//	return 0;
//}


//int main() {
//	string s;
//	cin >> s;
//	if (s.empty()) {
//		cout << 0 << endl;
//		return 0;
//	}
//	string tmp;
//	int size = s.size();
//	int i = size - 1;
//	while (s[i] == '1' && i >= 0) {
//		tmp += s[i];
//		i--;
//	}
//	s = tmp + s;
//	int cnt = 0;
//	for (i = s.size() - 1; i >= 0; i--) {
//		int tmp = 0;
//		while (s[i] == '1' && i >= 0) {
//			tmp++;
//			i--;
//		}
//		if (tmp>cnt) {
//			cnt = tmp;
//		}
//	}
//	cout << min(size, cnt) << endl;
//	return 0;
//}

//void Permutation(string S, int index, vector<string>& res) {
//	res.push_back(S);
//	if (index<0) {
//		return;
//	}
//	while (index >= 0) {
//		if (S[index] >= 'A' && S[index] <= 'Z') {
//			S[index] += 32;
//			Permutation(S, index - 1, res);
//			S[index] -= 32;
//		}
//		if (S[index] >= 'a' && S[index] <= 'z') {
//			S[index] -= 32;
//			Permutation(S, index - 1, res);
//			S[index] += 32;
//		}
//		index--;
//	}
//}
//
//void dfs(string s, int index, vector<string>& res) {
//	if (index == s.size()) {
//		res.push_back(s);
//		return;
//	}
//	dfs(s, index + 1, res);
//	if (s[index]<'0' || s[index]>'9') {
//		s[index] ^= (1 << 5);
//		dfs(s, index + 1, res);
//	}
//}
//vector<string> letterCasePermutation(string S) {
//	vector<string> res;
//	//Permutation(S, S.size() - 1, res);
//	dfs(S, 0, res);
//	return res;
//}
//
//int main() {
//	string s;
//	cin >> s;
//	vector<string> res = letterCasePermutation(s);
//	for (auto x : res) {
//		cout << x << endl;
//	}
//	system("pause");
//	return 0;
//
//}

//int check(int m, vector<int>& chart) {
//	for (int i = 0; i<m; i++) {
//		if (chart[i] == chart[m] || abs(chart[i] - chart[m]) == m - i) {
//			return 0;
//		}
//	}
//	return 1;
//}
//void Queens(int t, int& n, int& sum, vector<int>& chart) {
//	for (int j = 0; j<n; j++) {
//		chart[t] = j;
//		if (check(t,chart)) {
//			if (t == n - 1) {
//				sum++;
//			}
//			else {
//				Queens(t + 1, n, sum, chart);
//			}
//		}
//	}
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int sum = 0;
//		vector<int> chart(n, 0);
//		Queens(0, n, sum, chart);
//		printf("一共有%d种排列方式.", sum);
//	}
//	system("pause");
//	return 0;
//}


//int missingNumber(vector<int>& nums) {
//	int result = 1;
//	for (int i = 2; i <= nums.size(); i++) {
//		result = result ^ i;
//	}
//	for (int i = 0; i<nums.size(); i++) {
//		result = result ^ nums[i];
//	}
//	return result;
//}

//int longestOnes(vector<int>& A, int K) {
//	if (A.empty()) {
//		return 0;
//	}
//	int maxlen = 0;
//	int l = 0, r = 0;
//	int zero = 0;
//	for (r = 0; r<A.size(); r++) {
//		if (A[r] == 0) {
//			zero++;
//		}
//		while (zero > K) {
//			if (A[l] == 0) {
//				zero--;
//			}
//			l++;
//		}
//		maxlen = max(maxlen, r - l + 1);
//	}
//	return maxlen;
//}


//int main() {
//	int n;
//	cin >> n;
//	vector<int> v(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//
//	system("pause");
//	return 0;
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<string> chs(2 * n - 1, " ");
//	int i;
//	for (i = 0; i < 2 * n - 1; i++) {
//		cin >> chs[i];
//	}
//	string nums;
//	string fus;
//	i = 0;
//	while (i < 2 * n - 1) {
//
//		if (chs[i + 1] == "+") {
//			vector<string> tmp;
//			tmp.push_back(chs[i]);
//			while (i < 2 * n - 1 && chs[i + 1] == "+") {
//				fus += "+";
//				tmp.push_back(chs[i + 2]);
//				i = i + 2;
//			}
//			sort(tmp.begin(), tmp.end());
//			for (auto x : tmp) {
//				nums += x;
//			}
//		}
//		if (chs[i + 1] == "*") {
//			vector<string> tmp;
//			tmp.push_back(chs[i]);
//			while (i < 2 * n - 1 && chs[i + 1] == "*") {
//				fus += "*";
//				tmp.push_back(chs[i + 2]);
//				i = i + 2;
//			}
//			sort(tmp.begin(), tmp.end());
//			for (auto x : tmp) {
//				nums += x;
//			}
//		}
//		int csize = chs[i].size();
//		if (chs[i][csize-1] >= '0' && chs[i][csize-1] <= '9') {
//			nums += chs[i];
//		}
//		else {
//			fus += chs[i];
//		}
//		i++;
//	}
//	cout << nums << endl;
//	cout << fus << endl;
//	system("pause");
//	return 0;
//}

//int main() {
//	int n;
//	cin >> n;
//	if (n == 0) {
//		return 0;
//	}
//	vector<int> numbers(n, 0);
//	vector<char> opts(n - 1, 0);
//	cin >> numbers[0];
//	for (int i = 1; i < n; i++) {
//		cin >> opts[i - 1] >> numbers[i];
//	}
//
//	int from = 0;
//	for (int i = 1; i < n - 1; i++) {
//		if (opts[i] != opts[i - 1] || i==n-2) {
//			switch (opts[i-1])
//			{
//			case '+':
//				if (opts[i] == '-') {
//					sort(numbers.begin() + from, numbers.begin() + i + 1);
//					from = i + 1;
//				}
//				else {
//					sort(numbers.begin() + from, numbers.begin() + i + 2);
//					from = i + 1;
//				}
//				break;
//			case '-':
//				if (opts[i] != '-') {
//					sort(numbers.begin() + from, numbers.begin() + i + 1);
//				}
//				else {
//					sort(numbers.begin() + from + 1, numbers.begin() + i + 1);
//				}
//				from = i + 1;
//				break;
//			case '*':
//				sort(numbers.begin() + from, numbers.begin() + i + 1);
//				from = i + 1;
//				break;
//			case '/':
//				//sort(numbers.begin() + from, numbers.begin() + i + 1);
//				from = i + 1;
//				break;
//			}
//		}
//	}
//	cout << numbers[0];
//	for (int i = 1; i < n; i++) {
//		cout << " " << opts[i - 1] << " " << numbers[i];
//	}
//	system("pause");
//	return 0;
//}

//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//struct value {
//	int v;
//	int cnt;
//};
//
//bool cmp(value p1, value p2) {
//	return p1.cnt > p2.cnt;
//}
//
//vector<int> salary(int& n, vector<int>& vs) {
//	unordered_map<int, int> hash;
//	for (int i = 0; i < n; i++) {
//		hash[vs[i]]++;
//	}
//	value tmp;
//	vector<value> res;
//	unordered_set<int> sets;
//	for (int i = 0; i < n; i++) {
//		if (sets.count(vs[i])) {
//			continue;
//		}
//		else {
//			sets.insert(vs[i]);
//		}
//		tmp.v = vs[i];
//		tmp.cnt = hash[vs[i]];
//		res.push_back(tmp);
//	}
//	stable_sort(res.begin(), res.end(), cmp);
//	vector<int> result;
//	for (int i = 0; i < res.size(); i++) {
//		while (res[i].cnt--) {
//			result.push_back(res[i].v);
//		}
//	}
//	return result;
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<int> values(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> values[i];
//	}
//	vector<int> res = salary(n, values);
//	for (auto x : res) {
//		cout << x << " ";
//	}
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int dp2[601][601];
//int mytest(int v, int n, int m, int* volumes, int* masses, int* energies) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = v; j >= volumes[i - 1]; j--) {
//			for (int k = m; k >= masses[i - 1]; k--) {
//				dp2[j][k] = max(dp2[j][k], dp2[j - volumes[i - 1]][k - masses[i - 1]] + energies[i - 1]);
//			}
//		}
//	}
//	return dp2[v][m];
//}
////memset(dp, 0, sizeof(dp));
//
//int dp[601][601][601];
//int maxEnergyGenerate(int V, int N, int M, int* volumes, int* masses, int* energies) {
//	for (int i = 1; i <= N; i++) { //小瓶容量		
//		for (int j = V; j >= 0; j--) {  //反应器容量
//			for (int k = M; k >= 0; k--) {  //最大临界质量
//				if (j - volumes[i - 1]<0 || k - masses[i - 1]<0)
//					dp[i][j][k] = dp[i - 1][j][k];
//				else
//					dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - volumes[i - 1]][k - masses[i - 1]] + energies[i - 1]);
//			}
//		}
//	}
//
//	return dp[N][V][M];
//}
//
//
//
//int main() {
//
//	int v = 100, n = 5, m = 15;
//	int volumes[] = { 50,40,30,20,10 };
//	int masses[] = { 1,2,3,9,5 };
//	int energies[] = { 300,480,270,200,180 };
//
//	cout << maxEnergyGenerate(v, n, m, volumes, masses, energies) << endl;
//	cout << "new: " << endl;
//	cout << mytest(v, n, m, volumes, masses, energies) << endl;
//	system("pause");
//	return 0;
//}


//int main() {
//	int n;
//	cin >> n;
//	int z[4] = { 1,4,16,64 };
//	if (n == 1024) {
//		cout << 0 << endl;
//		return 0;
//	}
//	int total = 1024;
//	int k = 3;
//	int cnt = 0;
//	if (n > 0) {
//		while (k >= 0 && total > 0) {
//			if (total - z[k]) {
//				total -= z[k];
//				cnt++;
//			}
//			else {
//				k--;
//			}
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}

//int main() {
//	int n, i;
//	cin >> n;
//	vector<int> t(n, 0);
//	for (i = 0; i < n; i++) {
//		int h, m;
//		cin >> h >> m;
//		t[i] = h * 60 + m;
//	}
//	int x;
//	cin >> x;
//	int a, b;
//	cin >> a >> b;
//	int time = a * 60 + b;
//	sort(t.begin(), t.end());
//	for (i = n-1; i >=0 ; i--) {
//		if (t[i] <= time - x) {
//			break;
//		}
//	}
//	int rm = t[i] % 60;
//	int rh = t[i] / 60;
//	cout << rh << " " << rm << endl;
//	system("pause");
//	return 0;
//}


//int main() {
//	vector<int> deck = { 17,13,11,2,3,5,7 };
//	int n = deck.size();
//	deque<int> index;
//	for (int i = 0; i < n; i++) {
//		index.push_back(i);
//	}
//	vector<int> res(n);
//	sort(deck.begin(), deck.end());
//	for (auto x : deck) {
//		res[index.front()] = x;
//		index.pop_front();
//		if (!index.empty()) {
//			index.push_back(index.front());
//			index.pop_front();
//		}
//	}
//	for (auto x : res) {
//		cout << x << " ";
//	}
//	string s = "Hello";
//	transform(s.begin(), s.end(), s.begin(), ::tolower);
//	cout << s << endl;
//	system("pause");
//	return 0;
//}



//vector<vector<int>> generateMatrix(int n) {
//	vector<vector<int> > res(n, vector<int>(n, 0));
//	int c = 1;
//	int total = n * n;
//	int start = 0;
//	while (2 * start<total) {
//		int endx = n - start - 1;
//		int endy = n - start - 1;
//		for (int j = start; j <= endx; j++) {
//			res[start][j] = c++;
//		}
//		if (start<endy) {
//			for (int i = start + 1; i <= endy; i++) {
//				res[i][endx] = c++;
//			}
//		}
//		if (start<endx && start<endy) {
//			for (int j = endx - 1; j >= start; j--) {
//				res[endy][j] = c++;
//			}
//		}
//		if (start<endx && start<endy - 1) {
//			for (int i = endy - 1; i >= start + 1; i--) {
//				res[i][start] = c++;
//			}
//		}
//		++start;
//	}
//	return res;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int> > res = generateMatrix(n);
//	for (auto x : res) {
//		for (auto y : x) {
//			cout << y << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//vector<vector<int>> subsets(vector<int>& nums) {
//	int S = nums.size();
//	int N = (1 << S);
//	vector<vector<int>> res;
//	for (int i = 0; i < N; ++i) {
//		vector<int> v;
//		for (int j = 0; j < S; ++j)
//			if (i & (1 << j))
//				v.push_back(nums[j]);
//		res.push_back(v);
//	}
//	return res;
//}
//
//vector<vector<char>> subsets(vector<char>& nums) {
//	int S = nums.size();
//	int N = (1 << S);
//	vector<vector<char>> res;
//	for (int i = 0; i < N; ++i) {
//		vector<char> v;
//		for (int j = 0; j < S; ++j)
//			if (i & (1 << j))
//				v.push_back(nums[j]);
//		res.push_back(v);
//	}
//	return res;
//}
//int main() {
//	vector<char> nums = { 'a','b','c','d' };
//	vector<vector<char> > res = subsets(nums);
//	for (auto x : res) {
//		for (auto s : x) {
//			cout << s;
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}



//bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
//	return a.second > b.second;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	set<char> chs;
//	for (int i = 0; i < n; i++) {
//		char t;
//		cin >> t;
//		chs.insert(t);
//	}
//	vector<pair<char, int>> ti;
//	for (int i = 0; i < 13; i++) {
//		int tmp;
//		cin >> tmp;
//		ti.push_back(make_pair('A' + i, tmp));
//	}
//	sort(ti.begin(), ti.end(), cmp);
//	for (auto iter = ti.begin(); iter != ti.end(); iter++) {
//		if (chs.find(iter->first) == chs.end()) {
//			cout << iter->first << endl;
//			break;
//		}
//	}
//	return 0;
//}


//int main() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<int> > info(k, vector<int>(2, 0));
//	vector<int> p(n+1, 0);
//	vector<int> v(n+1, 0);
//	for (int i = 0; i < k; i++) {
//		cin >> info[i][0] >> info[i][1];
//		p[info[i][0]]++;
//		v[info[i][1]]++;
//	}
//	int cnt = 0;
//	int c = 0;
//	for (int i = 1; i <= n; i++) {
//		if (v[i] == 1) {
//			cnt++;
//		}
//		if (p[i] == 0) {
//			c++;
//		}
//	}
//	cnt += 2 * (n - c);
//	cout << cnt << endl;
//	system("pause");
//	return 0;
//}

//struct SameChar
//{
//	int st;
//	int en;
//	char c;
//	SameChar(int st, int en, char c) {
//		this->st = st;
//		this->en = en;
//		this->c = c;
//	}
//	SameChar() {
//		this->st = 0;
//		this->en = 0;
//		this->c = '\0';
//	}
//};
//
//int count0(int lowerCase, int upwerCase, int number) {
//	int n = 0;
//	if (lowerCase == 0) {
//		n++;
//	}
//	if (upwerCase == 0) {
//		n++;
//	}
//	if (number == 0) {
//		n++;
//	}
//	return n;
//}
//int find(vector<int> changes, int n) {
//	int n0 = -1;
//	int n1 = -1;
//	int n2 = -1;
//	for (int i = 0; i < changes.size(); i++) {
//		if (changes[i] > 0 && changes[i] % 3 == 0) {
//			n0 = i;
//		}
//		if (changes[i] > 0 && changes[i] % 3 == 1) {
//			n1 = i;
//		}
//		if (changes[i] > 0 && changes[i] % 3 == 2) {
//			n2 = i;
//		}
//	}
//	if (n == 0) {
//		return n0 > -1 ? n0 : (n2 > -1 ? n2 : n1);
//	}
//	if (n == 1) {
//		return n1 > -1 ? n1 : (n2 > -1 ? n2 : n0);
//	}
//	return -1;
//}
//int strongPasswordChecker(string str) {
//	if (str.empty()) {
//		return 6;
//	}
//	int lowerCase = 0;
//	int upwerCase = 0;
//	int number = 0;
//	vector<SameChar> samechars;
//	SameChar samechar;
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] >= 'a' && str[i] <= 'z') {
//			lowerCase++;
//		}
//		else if (str[i] >= 'A' && str[i] <= 'Z') {
//			upwerCase++;
//		}
//		else if (str[i] >= '0' && str[i] <= '9') {
//			number++;
//		}
//		if (samechar.c != str[i]) {
//			if (samechar.en - samechar.st >= 2) {
//				samechars.emplace_back(samechar.st, samechar.en, samechar.c);
//			}
//			samechar.c = str[i];
//			samechar.st = i;
//			samechar.en = i;
//		}
//		else {
//			samechar.en++;
//		}
//	}
//	if(samechar.en-samechar.st>=2){
//		samechars.emplace_back(samechar.st, samechar.en, samechar.c);
//	}
//	int needType = count0(lowerCase, upwerCase, number);
//	vector<int> changes(samechars.size());
//	for (int i = 0; i < samechars.size(); i++) {
//		changes[i] = samechars[i].en - samechars[i].st - 1;
//	}
//	int res = 0;
//	if (str.size() < 6) {
//		int tmp = 6 - str.size();
//		return max(tmp, needType);
//	}
//	else if (str.size() <= 20) {
//		int n = 0;
//		for (int l = 0; l < changes.size(); l++) {
//			n += changes[l] % 3 == 0 ? changes[l] / 3 : changes[l] / 3 + 1;
//		}
//		return max(n, needType);
//	}
//	else {
//		int res = 0;
//		int index = -1;
//		while (needType>0&& (index=find(changes,0))>-1)
//		{
//			changes[index] = max(changes[index] - 3, 0);
//			res++;
//			needType--;
//		}
//		int d = str.size() - 20;
//		while (d>0 && (index=find(changes,1))>-1)
//		{
//			d--;
//			res++;
//			changes[index]--;
//		}
//		int n = 0;
//		for (int l = 0; l < changes.size(); l++) {
//			n += changes[l] % 3 == 0 ? changes[l] / 3 : changes[l] / 3 + 1;
//		}
//		return res + d + needType + n;
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int> > box(n, vector<int>(m, 0));
//	vector<vector<int> > flag(n, vector<int>(m, 1));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> box[i][j];
//		}
//	}
//	int count = 0;
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < m - 1; j++) {
//			if (box[i][j] && box[i + 1][j] && box[i][j + 1] && box[i + 1][j + 1]
//				&& flag[i][j] && flag[i + 1][j] && flag[i][j + 1] && flag[i + 1][j + 1]) {
//				flag[i][j] = 0;
//				flag[i + 1][j] = 0;
//				flag[i][j + 1] = 0;
//				flag[i + 1][j + 1] = 0;
//				count++;
//			}
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//int main() {
//	string s = "3[a]2[b3[c]c]";
//	stack<int> nums;
//	stack<string> strs;
//	string res;
//	int num = 0;
//	for (int i = 0; i < s.size(); ++i) {
//		if (s[i] >= '0' && s[i] <= '9') {
//			num = num * 10 + s[i] - '0';
//		}
//		else if (s[i] == '[') {
//			nums.push(num);
//			strs.push(res);
//			num = 0;
//			res.clear();
//		}
//		else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
//			res += s[i];
//		}
//		else if (s[i] == ']') {
//			int k = nums.top();
//			nums.pop();
//			for (int j = 0; j < k; ++j) {
//				strs.top() += res;
//			}
//			res = strs.top();
//			strs.pop();
//		}
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int t;
//	cin >> t;
//	vector<int> N(t, 0);
//	vector<vector<int> > A;
//	for (int i = 0; i < t; i++) {
//		cin >> N[i];
//		vector<int> a(N[i], 0);
//		for (int j = 0; j < N[i]; j++) {
//			cin >> a[j];
//		}
//		A.push_back(a);
//	}
//	vector<string> res;
//	for (int i = 0; i < t; i++) {
//		map<int, int> hash;
//		for (int j = 0; j < N[i]; j++) {
//			hash[A[i][j]]++;
//		}
//		int same = 0;
//		for (auto iter = hash.begin(); iter != hash.end(); iter++) {
//			same = max(same, iter->second);
//		}
//		if (same > N[i] / 2) {
//			res.push_back("NO");
//		}
//		else {
//			res.push_back("YES");
//		}
//	}
//	for (auto x : res) {
//		cout << x << endl;
//	}
//	system("pause");
//	return 0;
//}

//int main() {
//	int n;
//	cin >> n;
//	string t;
//	cin >> t;
//	int m;
//	cin >> m;
//	vector<string> s(m);
//	for (int i = 0; i < m; i++) {
//		cin >> s[i];
//	}
//	for (auto x : t) {
//		if (!allch.count(x)) {
//			allch.insert(x);
//		}
//	}
//	string T;
//	for (auto x : allch) {
//		T += x;
//	}
//	int res = 0;
//	int total = allch.size();
//	for (int i = 0; i < m; i++) {
//		set<char> chs;
//		for (auto x : s[i]) {
//			if (!chs.count(x)) {
//				chs.insert(x);
//			}
//		}
//		string tmp;
//		for (auto x : chs) {
//			tmp += x;
//		} 
//		int size = s[i].size();
//		int k = 0;
//		while (k + size < total) {
//			if (T.substr(k, k + size) != tmp) {
//				break;
//			}
//			k = k + size;
//		}
//		if (k + size > total && T.substr(i, total) == s[i].substr(0, total - i)) {
//			res++;
//		}
//	}
//	string tmp = "asdfbsc";
//	cout << tmp.substr(1, 3) << endl;
//	cout << tmp.substr(2, 1) << endl;
//	//cout << res << endl;
//	system("pause");
//	return 0;
//}
//
//
//int main() {
//	int t, k;
//	cin >> t >> k;
//	vector<int> a(t,0);
//	vector<int> b(t, 0);
//	int tmp;
//	for (int i = 0; i < t; i++) {
//		cin >> a[i] >> b[i];
//		tmp = max(tmp, b[i]);
//	}
//	vector<long> cnt(tmp + 1, 0);
//	for (int i = 1; i <= tmp; i++) {
//		if (k == 1) {
//			cnt[i] = pow(2, i);
//			continue;
//		}
//		if (i < k) {
//			cnt[i] = 1;
//		}
//		else {
//			long sum = 0;
//			for (int j = 0; j*k <= i; j++) {
//				if (j == 0) {
//					sum++;
//				}
//				else {
//					long st = i - j*k + 1;
//					sum += st;
//				}
//			}
//			cnt[i] = sum;
//		}
//	}
//	vector<long> s_cnt(tmp + 1, 0);
//	for (int i = 1; i <= tmp; i++) {
//		s_cnt[i] += s_cnt[i - 1] + cnt[i];
//	}
//	for (int i = 0; i < t; i++) {
//		cout << s_cnt[b[i]] - s_cnt[a[i] - 1] << endl;
//	}
//	return 0;
//}
//
//
//
//long jie(long x) {
//	long result = 1;
//	for (int i = 1; i < x; i++) {
//		result *= i;
//	}
//	return result;
//}
//
//int main() {
//	int n, p, q;
//	cin >> n >> p >> q;
//	vector<long> dp(n + 2, 0);
//	dp[p] = jie(n) / jie(n)*jie(n - p);
//	for (int i = p; i < n - q; i++) {
//		dp[i + 1] = dp[i] * (n - i) / (i + 1);
//	}
//	long l = 0;
//	long r = 0;
//	for (int i = p; i < n - q + 1; i++) {
//		l += i*dp[i];
//		r += dp[i];
//	}
//	long res = 0;
//	for (long i = 0; i<long(1e9 + 7); i++) {
//		if ((i*long(1e9 + 7) + l) % r == 0) {
//			cout << (i*long(1e9 + 7) + l) / r << endl;
//			break;
//		}
//	}
//	return 0;
//}

//#define LL long long
//#define MOD 1000000007
//
//LL ans[100001];
//LL C[201][201];
//
//void c_table() {
//	memset(C, 0, sizeof(C));
//	for (int i = 0; i <= 200; i++) {
//		C[i][0] = 1;
//	}
//	for (int i = 1; i <= 200; i++) {
//		for (int j = 1; j <= i; j++) {
//			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//		}
//	}
//}
//
//int main() {
//	c_table();
//	int n, k;
//	cin >> n >> k;
//	ans[0] = 0;
//	ans[1] = 1;
//	for (int i = 2; i <= 100; i++) {
//		ans[i] = 0;
//		LL t = 0;
//		while (t*k <= i) {
//			ans[i] += C[i - t*k + t][t];
//			ans[i] %= MOD;
//			t++;
//		}
//	}
//	while (n--) {
//		int st, ed;
//		cin >> st >> ed;
//		LL qnmd = 0;
//		for (int i = st; i <= ed; i++) {
//			qnmd = (qnmd + ans[i]) % MOD;
//		}
//		cout << qnmd << endl;
//	}
//	system("pause");
//	return 0;
//}

//using namespace std;
//int main() {
//	string s;
//	cin >> s;
//	vector<int> index(256, -1);
//	for (int i = 0; i < s.size(); i++) {
//		index[s[i]] = i;
//	}
//	string res;
//	for (int i = 0; i < s.size(); i++) {
//		int end = index[s[i]];
//		for (int j = i + 1; j < end; j++) {
//			if (index[s[j]] > end) {
//				end = index[s[j]];
//			}
//		}
//		int t = end - i + 1;
//		res += to_string(t) + ",";
//		i = end;
//	}
//	res.pop_back();
//	cout << res << endl;
//
//
//	system("pause");
//	return 0;
//}

//bool matchAI(vector<int> P, vector<int> a, int nSize) {
//	for (int i = 0; i < nSize - 1; i++) {
//		if (a[i] == 1) {
//			if (P[i] <= P[i + 1]) {
//				return false;
//			}
//		}
//		else {
//			if (P[i] >= P[i + 1]) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//void Permutation(vector<int> P, vector<int>& a, int nSize, int n, long &cnt) {
//	if (n == nSize) {
//		if (matchAI(P, a, nSize)) {
//			cnt++;
//		}
//	}
//	else {
//		Permutation(P, a, nSize, n + 1, cnt);
//		for (int i = n + 1; i < nSize; ++i) {
//			if (P[n] != P[i]) {
//				int tmp = P[n];
//				P[n] = P[i];
//				P[i] = tmp;
//				Permutation(P, a, nSize, n + 1, cnt);
//				tmp = P[n];
//				P[n] = P[i];
//				P[i] = tmp;
//			}
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n - 1, 0);
//	for (int i = 0; i < n - 1; i++) {
//		cin >> a[i];
//	}
//	vector<int> P(n);
//	for (int i = 0; i < n; i++) {
//		P[i] = i;
//	}
//	long res = 0;
//	Permutation(P, a, n, 0, res);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}

//int main() {
//	int red, blue;
//	cin >> red >> blue;
//	int total = red+blue;
//	int B = 0;
//	float res = 0;
//	for (int i = 0; i < total-B; i += 3) {
//		res += 1.0 / (red + blue);
//		blue -= 3;
//		if (blue <= 0) {
//			break;
//		}
//	}
//	
//	for (int i = 0; i < total - B; i += 3) {
//		res += 1.0 / (red + blue);
//		blue -= 2;
//		B++;
//	}
//	printf("%.5f", res);
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//double helper(int n, int m, int sum, double pre)
//{
//	if (n == 0)
//		return 0;
//	double t = (double)n / sum * pre;
//	if (m <= 1)
//		return t;
//	pre = ((double)m / sum) * ((double)(m - 1) / (sum - 1));
//	m -= 2;
//	sum -= 2;
//	t += helper(n - 1, m, sum - 1, pre * (double)n / sum);
//	t += helper(n, m - 1, sum - 1, pre * (double)m / sum);
//	return t;
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int sum = n + m;
//	double pre = 1;
//	double res = helper(n, m, sum, pre);
//	printf("%.5f\n", res);
//	return 0;
//}


//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> q(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> q[i];
//	}
//	stack<int> sq;
//	vector<int> cnt(n, 0);
//	for (int i = 0; i != n; i++) {
//		while (!sq.empty() && q[sq.top()] < q[i]) {
//			sq.pop();
//		}
//		if (!sq.empty()) {
//			cnt[sq.top()]++;
//		}
//		sq.push(i);
//	}
//	int index = 0;
//	int res = 0;
//	for (int i = 0; i < n; i++) {
//		if(cnt[i]>index){
//			index = cnt[i];
//			res = q[i];
//		}
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}

//void helper(vector<string>& result, string res, string& s, int index) {
//	if (index == s.size()) {
//		result.push_back(res);
//		return;
//	}
//	if (index + 1 == s.size()) {
//		if (s[index] != '0') {
//			res += s[index] - '1' + 'A';
//			result.push_back(res);
//		}
//		return;
//	}
//	int t = (s[index] - '0') * 10 + (s[index + 1] - '0');
//	if ((t <= 0 || t > 26) && s[index + 1] == '0') {
//		return;
//	}
//	if (t > 26) {
//		res += s[index] - '1' + 'A';
//		helper(result, res, s, index + 1);
//	}
//	else if (s[index + 1] == '0') {
//		res += t - 1 + 'A';
//		helper(result, res, s, index + 2);
//	}
//	else {
//		res += s[index] - '1' + 'A';
//		helper(result, res, s, index + 1);
//		res.pop_back();
//		res += t - 1 + 'A';
//		helper(result, res, s, index + 2);
//		res.pop_back();
//	}
//}
//int main() {
//	string s;
//	getline(cin, s);
//	vector<string> result;
//	string res;
//	helper(result, res, s, 0);
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//vector<int> bucket;
//struct act {
//	int f;
//	int t;
//	int w;
//};
//int res;
//struct buc_state {
//	vector<int> state_vec;
//	act ac;
//	buc_state(int a, int b, int c, int f, int t, int w) {
//		state_vec.resize(3);
//		state_vec[0] = a;
//		state_vec[1] = b;
//		state_vec[2] = c;
//		ac.f = f;
//		ac.t = t;
//		ac.w = w;
//	}
//	buc_state() {
//		state_vec.resize(3);
//	}
//	void set_act(int d_w, int f, int t) {
//		ac.f = f;
//		ac.t = t;
//		ac.w = d_w;
//	}
//	bool is_empty(int buc_id) {
//		if (buc_id > 2) {
//			return false;
//		}
//		return (state_vec[buc_id] == 0);
//	}
//	bool is_full(int buc_id) {
//		return (state_vec[buc_id] >= bucket[buc_id]);
//	}
//	bool if_final() {
//		return (state_vec[0] == res && state_vec[1] == res);
//	}
//	bool dump_w(int f, int t, buc_state& next) {
//		vector<int> buc_w(this->state_vec);
//		int d_w = bucket[t] - state_vec[t];
//		if (buc_w[f] >= d_w) {
//			buc_w[t] += d_w;
//			buc_w[f] -= d_w;
//		}
//		else {
//			d_w = buc_w[f];
//			buc_w[t] += d_w;
//			buc_w[f] = 0;
//		}
//		if (d_w > 0) {
//			next.state_vec = buc_w;
//			next.set_act(d_w, f, t);
//			return true;
//		}
//		return false;
//	}
//};
//
//
//bool is_act_valid(buc_state& cur, int f, int t) {
//	if ((f != t) && !cur.is_empty(f) && !cur.is_full(t)) {
//		return true;
//	}
//	return false;
//}
//
//bool is_loop(vector<buc_state>& state, buc_state& next) {
//	for (int i = 0; i < state.size(); i++) {
//		if (equal(next.state_vec.begin(), next.state_vec.end(), state[i].state_vec.begin())) {
//			return true;
//		}
//	}
//	return false;
//}
//
//void dfs(vector<buc_state>& state, int& cnt, int& sht) {
//	buc_state cur = state.back();
//	if (cur.if_final()) {
//		++cnt;
//		sht = min(sht, static_cast<int>(state.size()));
//		return;
//	}
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (is_act_valid(cur, i, j)) {
//				buc_state next_state;
//				bool is_dump = cur.dump_w(i, j, next_state);
//				if (!is_dump && !is_loop(state, next_state)) {
//					state.push_back(next_state);
//					dfs(state, cnt, sht);
//					state.pop_back();
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	int x, y, z;
//	cin >> x >> y >> z >> res;
//	bucket.push_back(x);
//	bucket.push_back(y);
//	bucket.push_back(z);
//	vector<buc_state> state;
//	buc_state start(x, 0, 0, -1, 0, x);
//	state.push_back(start);
//	int cnt = 0;
//	int sht = INT_MAX;
//	dfs(state, cnt, sht);
//	cout << sht << endl;
//	system("pause");
//	return 0;
//}
//
//bool ishuiwen(string s) {
//	int n = s.size();
//	for (int i = 0; i<n / 2; i++) {
//		if (s[i] != s[n - 1 - i]) {
//			return false;
//		}
//	}
//	return true;
//}
//int main(){
//	string s;
//	cin >> s;
//	int n = s.size();
//	if (n <= 1) {
//		return 0;
//	}
//	int len = 0;
//	string res;
//	for (int i = 0; i<n; i++) {
//		for (int j = 1; j <= n-i; j++) {
//			string tmp = s.substr(i, j);
//			if (ishuiwen(tmp) && (tmp.size()>len)) {
//				res = tmp;
//				len = tmp.size();
//			}
//		}
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}



//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	int n = nums1.size();
//	int m = nums2.size();
//	if (n > m) {
//		return findMedianSortedArrays(nums2, nums1);
//	}
//	// Ci 为第i个数组的割, 比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
//	int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n+1长度
//	while (lo <= hi) {
//		c1 = (lo + hi) / 2;
//		c2 = m + n - c1;
//		LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
//		RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
//		LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
//		RMin2 = (c2 == 2*m) ? INT_MAX : nums2[c2 / 2];
//		if (LMax1 > RMin2) {
//			hi = c1 - 1;
//		}
//		else if (LMax2 > RMin1) {
//			lo = c1 + 1;
//		}
//		else {
//			break;
//		}
//	}
//	return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
//}
//int main() {
//	vector<int> nums1 = { 2,5 };
//	vector<int> nums2 = {1,4,7,9};
//	double res = findMedianSortedArrays(nums1, nums2);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}


//int main() {
//	vector<int> heights = { 2,1,5,6,2,3 };
//	int n = heights.size();
//	heights.push_back(0);
//	stack<int> stackh;
//	int maxarea = 0;
//	for (int i = 0; i <= n; i++) {
//		while (!stackh.empty() && heights[i] < heights[stackh.top()]) {
//			int top = stackh.top();
//			stackh.pop();
//			maxarea = max(maxarea, heights[top] * (stackh.empty() ? i : (i - stackh.top() - 1)));
//		}
//		stackh.push(i);
//	}
//	cout << maxarea << endl;
//	system("pause");
//	return maxarea;
//}





//int main() {
//	string word1, word2;
//	cin >> word1 >> word2;
//	int n = word1.size();
//	int m = word2.size();
//	vector<vector<int> > dp(n + 1, vector<int>(m + 1));
//	for (int i = 1; i <= n; i++) {
//		dp[i][0] = i;
//	}
//	for (int j = 1; j <= m; j++) {
//		dp[0][j] = j;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (word1[i] == word2[j]) {
//				dp[i][j] = dp[i - 1][j - 1];
//			}
//			else {
//				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
//			}
//		}
//	}
//	cout << dp[n][m] << endl;
//	system("pause");
//	return 0;
//}


//int main() {
//	int n;
//	cin >> n;
//	int N = int(sqrt(n*n));
//	int res = 0;
//	for (int i = 1; i <= n; i++) {
//		if ((2 * N)%i == 0 && ((2 * N / i) + 1 - i) % 2 == 0) {
//			++res;
//		}
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
//
//
//int main() {
//	string a, b, c;
//	//cin >> a >> b >> c;
//	a = "s#";
//	b = "::";
//	c = "a::3s#b::8s#c::9s#c::5";
//	int asize = a.size();
//	int bsize = b.size();
//	int csize = c.size();
//	map<string, int> hash;
//	int cur_pos = 0;
//	int i = 0;
//	while (i < csize) {
//		auto pos = c.find(b, cur_pos);
//		string tmp;
//		while (i < pos) {
//			tmp.push_back(c[i++]);
//		}
//		i += bsize;
//		cur_pos = i;
//		auto pos1 = c.find(a, i);
//		int tmp1 = 0;
//		if (pos1 == c.npos) {
//			while (i < csize) {
//				tmp1 = tmp1 * 10 + c[i++] - '0';
//			}
//			hash[tmp] += tmp1;
//			break;
//		}
//		while (i < pos1) {
//			tmp1 = tmp1 * 10 + c[i++] - '0';
//		}
//		hash[tmp] += tmp1;
//		i += asize;
//		cur_pos = i;
//	}
//	cout << hash.size() << endl;
//	for (auto iter = hash.begin(); iter != hash.end(); iter++) {
//		cout << iter->first << " " << iter->second << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//
//int main() {
//	string a, b, c;
//	a = "s#";
//	b = "::";
//	c = "a::3s#b::8s#c::9s#c::5";
//	size_t pre_pos = 0;
//	size_t cur_pos = 0;
//	vector<string> keys;
//	vector<string> values;
//	while (true) {
//		cur_pos = c.find(b, pre_pos);
//		if (cur_pos == c.npos) break;
//		keys.push_back(c.substr(pre_pos, cur_pos - pre_pos));
//		pre_pos = cur_pos + b.size();
//
//		cur_pos = c.find(a, pre_pos);
//		if (cur_pos == c.npos) cur_pos = c.size();
//		values.push_back(c.substr(pre_pos, cur_pos - pre_pos));
//		pre_pos = cur_pos + a.size();
//		if (pre_pos >= c.size()) break;
//	}
//	for (int i = 0; i < keys.size(); i++) {
//		cout << keys[i] << " " << values[i] << endl;
//	}
//	system("pause");
//	return 0;
//}


//string reco(string S){
//	int n = S.length();
//	if (n == 1) {
//		return S;
//	}
//	int maxlen = 0;
//	map<char, int> hash;
//	for (int i = 0; i < n; i++) {
//		hash[S[i]]++;
//		if (maxlen < hash[S[i]]) {
//			maxlen = hash[S[i]];
//		}
//	}
//	if (maxlen > (n + 1) / 2) {
//		return "";
//	}
//	string res(S);
//	int even = 0;
//	int odd = 1;
//	for (auto iter = hash.begin(); iter != hash.end(); iter++) { 
//		while (iter->second > 0 && iter->second < (n / 2 + 1) && odd < n) {
//			res[odd] = iter->first;
//			iter->second--;
//			odd += 2;
//		}
//		while (iter->second > 0) {
//			res[even] = iter->first;
//			iter->second--;
//			even += 2;
//		}
//	}
//	return res;
//}
//
//int main() {
//	string s = "abcdasdf";
//	string res = reco(s);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
//
//string reverseStr(string str) {
//	reverse(str.begin(), str.end());
//	return str;
//}
//
//string splitLoopedString(vector<string>& strs) {
//	int n = strs.size();
//	string ans;
//
//	for (int i = 0; i < n; ++i) {
//		string rest;
//		for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
//			rest += max(strs[j], reverseStr(strs[j]));
//		}
//
//		for (int j = 0; j < strs[i].size(); ++j) {
//			string head = strs[i].substr(j, strs[i].size() - j);
//			string tail = strs[i].substr(0, j);
//			ans = max(ans, head + rest + tail);
//		}
//
//		string rev = reverseStr(strs[i]);
//		for (int j = 0; j < rev.size(); ++j) {
//			string head = rev.substr(j, rev.size() - j);
//			string tail = rev.substr(0, j);
//			ans = max(ans, head + rest + tail);
//		}
//	}
//
//	return ans;
//}


//vector<int> parent;
//vector<int> Rank; //按秩合并
////路径压缩
//int unionsearch(int root) {
//	int son, tmp;
//	son = root;
//	while (root != parent[root]) {
//		root = parent[root];
//	}
//	while (son != root) {
//		tmp = parent[son];
//		parent[son] = root;
//		son = tmp;
//	}
//	return root;
//}
//
//int find(int x) {
//	while (x != parent[x]) {
//		parent[x] = parent[parent[x]];
//		x = parent[x];
//	}
//	return x;
//}
//void unionelements(int p, int q) {
//	int proot = find(p);
//	int qroot = find(q);
//	if (proot == qroot) {
//		return;
//	}
//	if (Rank[proot] < Rank[qroot]) {
//		parent[proot] = qroot;
//	}
//	else if (Rank[proot] > Rank[qroot]) {
//		parent[qroot] = proot;
//	}
//	else {
//		parent[proot] = qroot;
//		Rank[qroot] += 1;
//	}
//}
//
//
//vector<int> findRedundantConnection(vector<vector<int> > edges) {
//	vector<int> res(2);
//	int total = edges.size();
//	parent = vector<int>(total);
//	Rank = vector<int>(total);
//	for (int i = 0; i < total; i++) {
//		parent[i] = i;
//		Rank[i] = 1;
//	}
//	unionelements(edges[0][0] - 1, edges[0][1] - 1);
//	for (int i = 1; i < total; i++) {
//		if (find(edges[i][0] - 1) == find(edges[i][1] - 1)) {
//			res[0] = edges[i][0];
//			res[1] = edges[i][1];
//		}
//		else {
//			unionelements(edges[i][0] - 1, edges[i][1] - 1);
//		}
//	}
//	return res;
//}
//


//void bfs(vector<vector<int> > M, int i, queue<int> que, set<int> visited) {
//	que.push(i);
//	while (!que.empty()) {
//		int cur = que.front();
//		que.pop();
//		visited.insert(cur);
//		for (int k = 0; k < M[i].size(); k++) {
//			if (M[cur][k] == 1 && !visited.count(k)) {
//				que.push(k);
//			}
//		}
//	}
//}
//
//int findCircleNum(vector<vector<int> > M) {
//	int res = 0;
//	set<int> visited;
//	queue<int> que;
//	for (int i = 0; i < M.size(); i++) {
//		if (!visited.count(i)) {
//			bfs(M, i, que, visited);
//			res++;
//		}
//	}
//	return res;
//}


//int main() {
//	vector<int> A;
//	vector<int> B;
//	int R;
//	string s;
//	s = "A={1,3,5},B={2,4,5},R=2";
//	int i = 0;
//	if (s[i] == 'A' && s[i+1]=='=') {
//		i = i + 2;
//		if (s[i] == '{') {
//			i++;
//			int tmp=0;
//			while (s[i] != '}') {
//				if (s[i] != ',') {
//					tmp = tmp * 10 + s[i] - '0';
//				}
//				else {
//					A.push_back(tmp);
//					tmp = 0;
//				}
//				i++;
//			}
//			A.push_back(tmp);
//		}
//	}
//	i += 2;
//	if (s[i] == 'B' && s[i + 1] == '=') {
//		i = i + 2;
//		if (s[i] == '{') {
//			i++;
//			int tmp = 0;
//			while (s[i] != '}') {
//				if (s[i] != ',') {
//					tmp = tmp * 10 + s[i] - '0';
//				}
//				else {
//					B.push_back(tmp);
//					tmp = 0;
//				}
//				i++;
//			}
//			B.push_back(tmp);
//		}
//	}
//	i += 2;
//	if (s[i] == 'R' && s[i + 1] == '=') {
//		i = i + 2;
//		int tmp = 0;
//		while (i < s.size()) {
//			tmp = tmp * 10 + s[i] - '0';
//			i++;
//		}
//		R = tmp;
//	}
//	if(A.size()==0 || B.size()==0){
//		return 0;
//	}
//	int j = 0;
//	int k = 0;
//	vector<pair<int,int>> res;
//	while (j < A.size() && k < B.size()) {
//		if (A[j] <= B[k] && (B[k]-A[j])<=R) {
//			res.push_back(make_pair(A[j], B[k]));
//			j++;
//			k++;
//		}
//		else{
//			if (B[k] > A[j] + R) {
//				j++;
//			}
//			else {
//				while (B[++k] <= (A[j] + R)) {
//					if (A[j] <= B[k]) {
//						res.push_back(make_pair(A[j], B[k]));
//						break;
//					}
//				}
//				j++;
//				k++;
//			}
//		}
//	}
//	for (auto x : res) {
//		cout << '(' << x.first << ',' << x.second << ')';
//	}
//	system("pause");
//	return 0;
//}


//int main() {
//	int n;
//	cin >> n;
//	vector<int> nums(n);
//	for (int i = 0; i < n; i++) {
//		cin >> nums[i];
//	}
//
//}

//bool cmp(vector<string>a, vector<string>b) {
//	if (a[0] < b[0]) {
//		return true;
//	}
//	else if(a[1]<b[1]) {
//		return true;
//	}
//	return false;
//}
//
//int main() {
//	int n;
//	//cin >> n;
//	n = 3;
//	vector<vector<string>> info = { {
//			"cz7132","a1","zhangsan"},
//			{"cz7132","a2","zhaosi"},
//			{"cz7156","a2","wangwu"} };
//	map<string, vector<string>> hash;
//	for (int i = 0; i < n; i++) {
//		//vector<string> hzc(3);
//		//cin >> hzc[0] >> hzc[1] >> hzc[2];
//		//info.push_back(hzc);
//		hash[info[i][2]] = { info[i][0], info[i][1] };
//	}
//	int m;
//	//cin >> m;
//	m = 2;
//	vector<vector<string>> change = {
//		{"cz7132","a1","cz7156","a2"},
//		{"cz7156","a2","cz7156","a3"} };
//	for (int i = m-1; i >= 0; i--) {
//		//vector<string> ch(4);
//		//cin >> ch[0] >> ch[1] >> ch[2] >> ch[3];
//		//change.push_back(ch);
//		for (auto iter = hash.begin(); iter != hash.end(); iter++) {
//			if (iter->second[0] == change[i][0] && iter->second[1] ==change[i][1]) {
//				iter->second[0] = change[i][2];
//				iter->second[1] = change[i][3];
//			}
//		}
//	}
//	vector<vector<string>> res;
//	for (auto iter = hash.begin(); iter != hash.end(); iter++) {
//		vector<string> res1;
//		res1.push_back(iter->second[0]);
//		res1.push_back(iter->second[1]);
//		res1.push_back(iter->first);
//		res.push_back(res1);
//	} 
//	sort(res.begin(), res.end(), cmp);
//	for (auto x : res) {
//		cout << x[0] <<" "<< x[1] << " "<< x[2] << endl;
//	}
//	system("pause");
//	return 0;
//}





//using namespace std;
//vector<vector<int> > moves = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
//
//bool valid(pair<int, int>& cur, int& m, int& n,int& k) {
//	if (cur.first < 0 || cur.first >= m || cur.second < 0 || cur.second >= n) {
//		return false;
//	}
//	int left = 0;
//	string l = to_string(cur.first);
//	for (auto x : l) {
//		left += x - '0';
//	}
//	int right = 0;
//	string r = to_string(cur.second);
//	for (auto x : r) {
//		right += x - '0';
//	}
//	if ((left + right) <= k) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//void bfs(pair<int, int> cur, vector<vector<int> >& flag, int& m, int& n, int& k, int& res) {
//	flag[cur.first][cur.second] = 0;
//	queue<pair<int, int> > que;
//	que.push(cur);
//	while (!que.empty()) {
//		pair<int, int> tmp = que.front();
//		res++;
//		que.pop();
//		for (int i = 0; i<4; i++) {
//			int next_i = tmp.first + moves[i][0];
//			int next_j = tmp.second + moves[i][1];
//			pair<int, int> next = make_pair(next_i, next_j);
//			if (valid(next, m, n, k) && flag[next.first][next.second]) {
//				que.push(next);
//				flag[next.first][next.second] = 0;
//			}
//		}
//	}
//	return;
//}
//int main() {
//	int m, n, k;
//	cin >> m >> n >> k;
//	vector<vector<int> > flag(m, vector<int>(n, 1));
//	int res = 0;
//	pair<int, int> cur = make_pair(0, 0);
//	if (flag[0][0] && valid(cur, m, n, k)) {
//		bfs(cur, flag, m, n, k, res);
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
//


//bool isValidSudoku(vector<vector<char>>& board) {
//	vector<unordered_map<int, int>> row(9), col(9), block(9);
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			int bindex = (i / 3) * 3 + j / 3;
//			char cur = board[i][j];
//			if (cur == '.') {
//				continue;
//			}
//			if (row[i].count(cur) || col[j].count(cur) || block[bindex].count(cur)) {
//				return false;
//			}
//			row[i][cur] = 1;
//			col[j][cur] = 1;
//			block[bindex][cur] = 1;
//		}
//	}
//	return true;
//}

//int main() {
//	string s1 = "abcdef";
//	string s2 = "bcdea";
//	int n = s1.size();
//	int m = s2.size();
//	vector<vector<int> > dp(n+1, vector<int>(m+1));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (s1[i - 1] == s2[j - 1]) {
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			else {
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//
//}
//
//vector<vector<int>> moves = { { 1,0 },{ 0,1 } };
//void bfs(vector<vector<int>>& box, vector<vector<int> >& flag, pair<int,int> cur, vector<pair<int, int>>& path, int& pre, int& res) {
//	queue<pair<int, int>> que;
//	que.push(cur);
//	int n = box.size();
//	int m = box[0].size();
//	while (!que.empty()) {
//		for (int i = 0; i < 2; i++) {
//			pair<int, int> next = make_pair(cur.first + moves[i][0], cur.second + moves[i][1]);
//			if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < m) {
//				flag[next.first][next.second] = 0;
//				pre += box[next.first][next.second];
//				path.push_back(next);
//				bfs(box, flag, next, path, pre, res);
//				path.pop_back();
//				pre -= box[next.first][next.second];
//				flag[next.first][next.second] = 1;
//			}
//		}
//	}
//	return;
//}
//
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int> > box(n, vector<int>(m));
//	vector<vector<int> > flag(n, vector<int>(m, 1));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> box[i][j];
//		}
//	}
//	vector<pair<int, int> > path;
//	int res = 0;
//	int pre = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if(flag[i][j])
//				bfs(box, flag, make_pair(i, j), path,pre, res);
//		}
//	}
//	system("pause");
//	return 0;
//}


//vector<int> topKFrequent(vector<int>& nums, int k) {
//	unordered_map<int, int> hash;
//	int maxcnt = 0;
//	for (auto x : nums) {
//		hash[x]++;
//		maxcnt = max(maxcnt, hash[x]);
//	}
//	vector<vector<int> > buckets(maxcnt+1);
//	for (auto item : hash) {
//		buckets[item.second].push_back(item.first);
//	}
//	vector<int> res;
//	for (int i = maxcnt; i >= 0 && k > 0; i--) {
//		if (buckets[i].empty()) continue;
//		for (auto x : buckets[i]) {
//			if (k > 0) {
//				k--;
//				res.push_back(x);
//			}
//			else {
//				break;
//			}
//		}
//	}
//	return res;
//}

//typedef pair<int, int> ipair;
//struct cmp
//{
//	bool operator()(const ipair& left, const ipair& right) {
//		return left.second > right.second;
//	}
//};
//
//
//vector<int> topKFrequent(vector<int>& nums, int k) {
//	unordered_map<int, int> hash;
//	for (auto x : nums) {
//		hash[x]++;
//	}
//	priority_queue<ipair, vector<ipair>,cmp> que;
//	for (auto item : hash) {
//		if (que.size() < k) {
//			que.push(item);
//		}
//		else if (item.second > que.top().second) {
//			que.pop();
//			que.push(item);
//		}
//	}
//	vector<int> res(que.size(), 0);
//	while (!que.empty()) {
//		res[que.size() - 1] = que.top().first;
//		que.pop();
//	}
//	return res;
//}

//vector<string> topKFrequent(vector<string>& words, int k) {
//	unordered_map<string, int> hash;
//	int maxlen = 0;
//	for (auto w : words) {
//		hash[w]++;
//		maxlen = max(maxlen, hash[w]);
//	}
//	vector<vector<string>> buckets(maxlen+1);
//	for (auto item : hash) {
//		buckets[item.second].push_back(item.first);
//	}
//	vector<string> res;
//	for (int i = maxlen; i >= 0 & k > 0; i--) {
//		if (buckets[i].empty()) continue;
//		sort(buckets[i].begin(), buckets[i].end());
//		for (auto x : buckets[i]) {
//			if (k > 0) {
//				res.push_back(x);
//				k--;
//			}
//			else {
//				break;
//			}
//
//		}
//	}
//	return res;
//}

//double dist(const vector<int>& x) {
//	return (x[0] * x[0] + x[1] * x[1]);
//}
//
//struct cmp {
//	bool operator()(const vector<int>& left, const vector<int>& right) const {
//		return dist(left) < dist(right);
//	}
//};
//
//vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//	priority_queue<vector<int>, vector<vector<int>>, cmp> q;
//	for (auto x : points) {
//		if (q.size() < K) {
//			q.push(x);
//		}
//		else if (dist(x) < dist(q.top())) {
//			q.pop();
//			q.push(x);
//		}
//	}
//	vector<vector<int> > res(q.size());
//	while (!q.empty()) {
//		res[q.size() - 1] = q.top();
//		q.pop();
//	}
//	return res;
//}


//ListNode* merge2List(ListNode* l1, ListNode* l2) {
//	if (!l1 && !l2) {
//		return nullptr;
//	}
//	if (!l1) {
//		return l2;
//	}
//	if (!l2) {
//		return l1;
//	}
//	ListNode* head = new ListNode(-1);
//	ListNode* point = head;
//	while (l1 || l2) {
//		if (l1->val <= l2->val) {
//			point->next = l1;
//			l1 = l1->next;
//		}
//		else {
//			point->next = l2;
//			l2 = l2->next;
//		}
//		point = point->next;
//	}
//	if (l1) {
//		point->next = l1;
//	}
//	if (l2) {
//		point->next = l2;
//	}
//	return head->next;
//}
//
//ListNode* mergeKLists(vector<ListNode*>& lists) {
//	int cnt = lists.size();
//	int k = 1;
//	while (k < cnt) {
//		for (int i = 0; i < cnt - k; i += 2*k) {
//			lists[i] = merge2List(lists[i], lists[i + k]);
//		}
//		k *= 2;
//	}
//	if (cnt > 0) {
//		return lists[0];
//	}
//	else {
//		return nullptr;
//	}
//}


//vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//	int n = arr.size();
//	int right = arr.size() - 1;
//	int left = 0;
//	int mid = 0;
//	while (left <= right) {
//		mid = left + (right - left) / 2;
//		if (arr[mid]<x) {
//			left = mid + 1;
//		}
//		else if (arr[mid]>x) {
//			right = mid - 1;
//		}
//		else {
//			break;
//		}
//	}
//	int index = mid;
//	int low = index - 1;
//	int high = index + 1;
//	vector<int> res;
//	res.push_back(arr[index]);
//	while (low >= 0 && high <= n - 1) {
//		if (x - arr[low] <= arr[high] - x) {
//			res.insert(res.begin(), arr[low]);
//			low--;
//		}
//		else {
//			res.push_back(arr[high]);
//			high++;
//		}
//		if (res.size() == k) {
//			break;
//		}
//	}
//	if (res.size()<k) {
//		while (low >= 0) {
//			res.insert(res.begin(), arr[low--]);
//			if (res.size() == k) {
//				break;
//			}
//		}
//		while (high <= n - 1) {
//			res.push_back(arr[high++]);
//			if (res.size() == k) {
//				break;
//			}
//		}
//	}
//	return res;
//}


//class Solution {
//private:
//	vector<vector<string> > output;
//	vector<int> queens;
//	bool judge(int k) {
//		for (int i = 0; i < k; i++) {
//			if (abs(k - i) == abs(queens[k] - queens[i]) || queens[k] == queens[i]) {
//				return false;
//			}
//		}
//		return true;
//	}
//	void print(vector<int> res) {
//		vector<string> str;
//		for (auto x : res) {
//			string substr;
//			for (int i = 0; i < res.size(); i++) {
//				if (i == x) {
//					substr.append("Q");
//				}
//				else {
//					substr.append(".");
//				}
//			}
//			str.push_back(substr);
//		}
//		output.push_back(str);
//	}
//	void backtrace(int t, int n) {
//		if (t >= n) {
//			print(queens);
//		}
//		else {
//			for (int i = 0; i < n; i++) {
//				queens[t] = i;
//				if (judge(t)) {
//					backtrace(t + 1, n);
//				}
//			}
//		}
//	}
//public:
//	vector<vector<string> > solveNQueens(int n) {
//		queens = vector<int>(n);
//		for (int i = 0; i < queens.size(); i++) {
//			queens[i] = 0;
//		}
//		backtrace(0, n);
//		return output;
//	}
//};

//
//class Solution {
//private:
//	vector<vector<int> > output;
//	void backtrace(vector<int>& nums, int t, int& n) {
//		if (t == n) {
//			output.push_back(nums);
//		}
//		else {
//			for (int i = t; i < n; i++) {
//				swap(nums[t], nums[i]);
//				backtrace(nums, t + 1, n);
//				swap(nums[t], nums[i]);
//			}
//		}
//	}
//public:
//	vector<vector<int>> permute(vector<int>& nums) {
//		int n = nums.size();
//		backtrace(nums, 0, n);
//		return output;
//	}
//};


//class Solution {
//private:
//	vector<int> nums;
//	vector<vector<int> > res;
//	vector<int> path;
//	void dfs(int level, vector<bool>& visit) {
//		if (level < 0) {
//			res.push_back(path);
//			return;
//		}
//		for (int i = 0; i < nums.size(); i++) {
//			if (visit[i] || i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]) {
//				continue;
//			}
//			visit[i] = true;
//			path.push_back(nums[i]);
//			dfs(level - 1, visit);
//			path.pop_back();
//			visit[i] = false;
//		}
//	}
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		vector<bool> visit(nums.size(), false);
//		this->nums = nums;
//		dfs(nums.size() - 1, visit);
//		return res;
//	}
//};
//
//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//	unordered_map<int, set<vector<int>>> dict;
//	for (int i = 1; i <= target; i++) {
//		for (int it : candidates) {
//			if (i == it) dict[i].insert(vector<int>{it});
//			else if (i > it) {
//				for (auto ivec : dict[i - it]) {
//					ivec.push_back(it);
//					sort(ivec.begin(), ivec.end());
//					if (dict[i].count(ivec) == 0) {
//						dict[i].insert(ivec);
//					}
//				}
//			}
//		}
//	}
//	vector<vector<int>> ans;
//	for (auto it : dict[target]) ans.push_back(it);
//	return ans;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	string s;
//	//cin >> s;
//	s = "RRRRRLRLRLL";
//	stack<char> st;
//	vector<int> dp(s.size(), 0);
//	for (int i = 0; i < s.size(); i++) {
//		
//		if (s[i] == 'L') {
//			while (!st.empty())
//			{
//				if (st.size() % 2 == 0) {
//					dp[i]++;
//				}
//				else {
//					dp[i-1]++;
//				}
//				st.pop();
//			}
//			if (s[i-1]=='R'){
//				dp[i]++;
//			}
//		}
//		else {
//			st.push(s[i]);
//		}
//	}
//	for (auto c : dp) {
//		cout << c << " ";
//	}
//	system("pause");
//	return 0;
//}

//int main() {
//	map<int, int> hash;
//	cout << hash[1] << endl;
//	system("pause");
//	return 0;
//}


//int main() {
//	int n;
//	cin >> n;
//	vector<int> dp(n+1);
//	for (int i = 1; i <= n; i++) {
//		dp[i] = i;
//		for (int j = 1; i - j*j >= 0; j++) {
//			dp[i] = min(dp[i], dp[i - j*j]+1);
//		}
//	}
//	cout << dp[n] << endl;
//	system("pause");
//	return 0;
//}


//int main() {
//	int m, n;
//	char c;
//	cin >> m >> c >> n;
//	vector<vector<int>> box(m, vector<int>(n));
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n-1; j++) {
//			cin >> box[i][j] >> c;
//		}
//		cin >> box[i][n - 1];
//	}
//	vector<vector<int>> dp(m, vector<int>(n));
//	int res = 0;
//	for (int i = 0; i < m; i++) {
//		if (box[i][0]) {
//			dp[i][0] = 1;
//		}
//	}
//	for (int j = 0; j < n; j++) {
//		if (box[0][j]) {
//			dp[0][j] = 1;
//		}
//	}
//	for (int i = 1; i < m; i++) {
//		for (int j = 1; j < n; j++) {
//			if (box[i][j]) {
//				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//				res = max(dp[i][j], res);
//			}
//		}
//	}
//	cout << res*res << endl;
//	system("pause");
//	return 0;
//}

//int findMaxConsecutiveOnes(vector<int>& nums) {
//	int res = 0;
//	int pre = 0;
//	int cur = 0;
//	int size = nums.size();
//	while (cur < size) {
//		if (nums[cur]) {
//			cur++;
//		}
//		else {
//			cur++;
//			int tmp = cur;
//			while (cur<size && nums[cur]) {
//				cur++;
//			}
//			res = max(res, cur - pre);
//			pre = tmp;
//		}
//	}
//	res = max(res, cur - pre);
//	return res;
//}
//int main() {
//	vector<int> nums = { 1,1,0,1,1,1,0,1 };
//	int res = findMaxConsecutiveOnes(nums);
//	cout << res << endl;
//  	system("pause");
//	return 0;
//}


//
//ListNode* reverseKnode(ListNode* head, int& k) {
//	if (!head->next) {
//		return nullptr;
//	}
//	ListNode *p, *q;
//	p = q = head->next;
//	int i = 0;
//	while (p) {
//		p = p->next;
//		if (i >= k) {
//			q = q->next;
//		}
//		i++;
//	}
//	return i < k ? nullptr : q;
//}
//
//int main() {
//	ListNode *head = new ListNode(-1);
//	ListNode *cur = head;
//	int n;
//	while (cin >>n)
//	{
//		ListNode* tmp = new ListNode(n);
//		cur->next = tmp;
//		cur = tmp;
//		if (cin.get() == '\n') {
//			break;
//		}
//	}
//	int k;
//	cin >> k;
//	ListNode* node = reverseKnode(head, k);
//	cout << node->val << endl;
//	system("pause"); 
//	return 0;
//}

//int main() {
//	int n;
//	cin >> n;
//	int m = n - 2;
//	int half = 2 * m - 1;
//	int total = 2 * half;
//	for (int i = 0; i < total; i++) {
//		if ((i == half / 2) || i == (half / 2 + half)) {
//			cout << "*";
//		}
//		else {
//			cout << " ";
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < total; i++) {
//		if (abs(i- half / 2)==1 || abs(i-(half / 2 + half))==1) {
//			cout << "*";
//		}
//		else {
//			cout << " ";
//		}
//	}
//	cout << endl;
//	for (int i = 2; i < m; i++) {
//		for (int j = 0; j < total; j++) {
//			if (abs(j - half / 2) == i || abs(j - half / 2) == i-1 || abs(j - half / 2 - half) == i || abs(j - half / 2 - half) == i-1) {
//				cout << "*";
//			}
//			else {
//				cout << " ";
//			}
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < total; i++) {
//		cout << "*";
//	}
//	cout << endl;
//	cout << " ";
//	for (int i = 0; i < total - 2; i++) {
//		cout << "*";
//	}
//	cout << " " << endl;
//	system("pause");
//	return 0;
//}
//
//void change(string& a, string& b, int k) {
//	string tmp = a.substr(0, k);
//	a = b.substr(0, k) + a.substr(k);
//	b = tmp + b.substr(k);
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<string> str(n);
//	set<string> sets;
//	vector<set<char>> nums(m);
//	for (int i = 0; i < n; i++) {
//		cin >> str[i];
//		//sets.insert(str[i]);
//		for (int k = 0; k < m;k++) {
//			if (!nums[k].count(str[i][k])) {
//				nums[k].insert(str[i][k]);
//			}
//		}
//	}
//	long res = nums[0].size();
//	for (int i = 1; i < m; i++) {
//		res = res * nums[i].size() % 1000000007;
//	}
//	cout << res << endl;
//
//	/*
//	for (int k = 1; k < m; k++) {
//		int t = str.size();
//		for (int i = 0; i < t - 1; i++) {
//			for (int j = i + 1; j < t; j++) {
//				string tmp1 = str[i].substr(0, k) + str[j].substr(k);
//				string tmp2 = str[j].substr(0, k) + str[i].substr(k);
//				if (!sets.count(tmp1)) {
//					sets.insert(tmp1);
//					str.push_back(tmp1);
//				}
//				if (!sets.count(tmp2)) {
//					sets.insert(tmp2);
//					str.push_back(tmp2);
//				}
//			}
//		}
//	}
//	cout << sets.size()% 1000000007 << endl;
//	*/
//	system("pause");
//	return 0;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int m;
//	for (int i = 0; i<n; i++) {
//		cin >> m;
//		vector<int> nums;
//		int tmp;
//		for (int j = 0; j<m; j++) {
//			cin >> tmp;
//			nums.push_back(m - tmp);
//		}
//		int flg = true;
//		for (int k = 0; k<m - 1; k++) {
//			if (nums[k]>nums[k + 1]) {
//				flg = false;
//				break;
//			}
//		}
//		if (flg) {
//			cout << "Yes" << endl;
//		}
//		else {
//			cout << "No" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}



//int main(void) {
//	string str;
//	//cin >> str;
//	str = "abbabb";
//	int n = str.size();
//	vector<int> res(n,1);
//	for (int i = n - 1; i >= 0; i--) {
//		for (int j = 0; j < n - 1 - i; j++) {
//			if (str[i + j ] != str[j]) {
//				res[i] = 0;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cout << res[i];
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//char s1[1000];
//int Next[1000];
//int l;
//void getNext(char s1[], int Next[])
//{
//	int i, j;
//	j = -1;
//	i = 0;
//	Next[i] = -1;
//	while (s1[i] != '\0')
//	{
//		while (j != -1 && s1[j] != s1[i])
//			j = Next[j];
//		i++;
//		j++;
//		Next[i] = j;
//	}
//	return;
//}
//int main()
//{
//	int t, i, ans;
//
//	while (scanf("%s", s1) != EOF)
//	{
//		getNext(s1, Next);
//		int n;
//		n = ans = strlen(s1);
//		for (int l = 0; l < n; l++) {
//			i = Next[l];
//			while (i != -1)
//			{
//				int k = l - i;//最小循环节 
//				int p = l%k;//循环k节点若干次后剩余部分的长度
//				int q = (k - p) % k;//q为字符串s1要想补齐成恰好整数个k所需要的最少字符数 
//				if (l + q >= k * 2)//判断循环是否超过两次
//					ans = min(ans, p);
//				i = Next[i];
//			}
//			printf("%d\n", ans);//输出最小补全长度 
//		}
//	}
//	return 0;
//}


//double find_kth(vector<int> nums1, int nums1_begin, vector<int> nums2, int nums2_begin, int k) {
//	if (nums1_begin >= nums1.size()) {
//		return nums2[nums2_begin + k - 1];
//	}
//	if (nums2_begin >= nums2.size()) {
//		return nums1[nums1_begin + k - 1];
//	}
//	if (k == 1) {
//		return min(nums1[nums1_begin], nums2[nums2_begin]);
//	}
//	int nums1_mid = INT_MAX;
//	int nums2_mid = INT_MAX;
//	if (nums1_begin + k / 2 - 1 < nums1.size()) {
//		nums1_mid = nums1[nums1_begin + k / 2 - 1];
//	}
//	if (nums2_begin + k / 2 - 1 < nums2.size()) {
//		nums2_mid = nums2[nums2_begin + k / 2 - 1];
//	}
//	if (nums1_mid < nums2_mid) {
//		return find_kth(nums1, nums1_begin + k / 2, nums2, nums2_begin, k - k / 2);
//	}
//	return find_kth(nums1, nums1_begin, nums2, nums2_begin + k / 2, k - k / 2);
//}
//
//double findmid(vector<int> nums1, vector<int> nums2) {
//	int m = nums1.size();
//	int n = nums2.size();
//	if (m == 0) {
//		if (n % 2 != 0) {
//			return 1.0*nums2[n / 2];
//		}
//		return (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0;
//	}
//	if (n == 0) {
//		if (m % 2 != 0) {
//			return 1.0*nums1[m / 2];
//		}
//		return (nums1[m / 2] + nums1[m / 2 - 1]) / 2.0;
//	}
//	int total = m + n;
//	if ((total & 1) == 1)
//		return find_kth(nums1, 0, nums2, 0, total / 2 + 1);
//	return (find_kth(nums1, 0, nums2, 0, total / 2) + find_kth(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
//}
//
//int main(){
//	vector<int> nums1 = { 1,2,3,4,5,7,44};
//	vector<int> nums2 = { 2};
//	double res = findmid(nums1, nums2);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}

bool cmp(pair<int, double> a, pair<int, double> b) {
	return a.second > b.second;
}

int main() {
	vector<int> l = { 1,1,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0 };
	vector<double> p = { 0.9,0.8,0.7,0.6,0.55,0.54,0.53,0.52,0.51,0.505,0.4,0.39,0.38,0.37,0.36,0.35,0.34,0.33,0.30,0.1 };
	vector<pair<int, double>> points;
	for (int i = 0; i < l.size(); i++) {
		points.push_back(make_pair(l[i], p[i]));
	}
	sort(points.begin(), points.end(), cmp);
	double area = 0;
	double fpr = 0;
	double tpr = 0;
	double P = 0;
	double N = 0;
	for (auto c : l) {
		if (c) {
			P += 1;
		}
		else {
			N += 1;
		}
	}
	cout << "roc curve" << endl;
	vector<pair<double, double>> roc;
	for (int i = 0; i < points.size(); i++) {
		if (points[i].first == 1) {
			tpr += 1.0 / P;
		}
		else {
			fpr += 1.0 / N;
			area += tpr / N;
		}
		roc.push_back(make_pair(fpr, tpr));
	}
	roc.insert(roc.begin(),make_pair(0, 0));
	for (auto iter = roc.begin(); iter != roc.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
	cout << "auc:" << area << endl;
	cout << "pr curve" << endl;
	vector<pair<double, double>> pr;
	double recall = P;
	double precision = 0;
	double ap = 0;
	for (int i = points.size() - 1; i >= 0; i--) {
		if (points[i].first == 1) {
			precision = max(precision, recall / (i + 1));
			pr.push_back(make_pair(recall / P, precision));
			ap += precision;
			recall -= 1;
		}
	}
	ap /= P;
	reverse(pr.begin(), pr.end());
	for (auto iter = pr.begin(); iter != pr.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
	cout << "Ap:" << ap << endl;
	system("pause");
	return 0;
}
