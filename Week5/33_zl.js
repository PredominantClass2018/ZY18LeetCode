//1668 正则表达式函数的使用
var maxRepeating = function(sequence, word) {
    const range = new RegExp(`${word}`, 'g');

    const data = sequence.replace(range, '*').split('');

    let result = 0,
        max = 0;

    for (let i = 0; i < data.length; i++) {
        if (data[i] === '*') max++;
        if (data[i + 1] !== '*') {
            result = Math.max(max, result);
            max = 0;
        }
    }
    return result;
};
//141  可以采用三种办法实现a.直接哈希表查看是否被访问过b.利用json的stringify函数实现c.使用双指针实现
//a.hash方法
var hasCycle = (head) => {
        if (!head || !head.next) return false
        let map = new Map()
        while (head) {
            if (map.has(head)) return true
            map.set(head, true)
            head = head.next
        }
        return false
    }
    //b.json方法
var hasCycle = function(head) {
    try {
        JSON.stringify(head)
        return false
    } catch {
        return true
    }
};
//c.快慢指针
var hasCycle = function(head) {
    if (!head || !head.next) return false
    let slow = head
    let fast = head.next
    while (slow != fast) {
        if (!fast || !fast.next) return false
        fast = fast.next.next
        slow = slow.next
    }
    return true
};
//1669
var mergeInBetween = function(list1, a, b, list2) {
    let cur = list1
    for (let i = 0; i < a - 1; i++) {
        cur = cur.next
    }
    let node = cur.next
    for (let i = a; i < b + 1; i++) {
        node.next = list2
    }
    while (cur.next)
        cur = cur.next;
    cur.next = node;
    return list1;
};