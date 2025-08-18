class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Slow aur Fast pointers bana lo
        int slow = nums[0];  
        int fast = nums[0];

        // Step 2: Move karo pointers ko jab tak woh cycle ke andar mil nahi jaate
        // slow ek ek step aage badhega, fast do do step aage badhega
        do {
            slow = nums[slow];          // ek step
            fast = nums[nums[fast]];    // do step
        } while (slow != fast);

        // Jab yeh loop break hoga -> iska matlab slow aur fast ek cycle me mil gaye hain

        // Step 3: Ab ek naya pointer start karo nums[0] se
        int ptr1 = nums[0];
        int ptr2 = slow;   // slow abhi cycle ke andar hai

        // Step 4: Dono ko ek ek step chalate raho jab tak woh same jagah na aa jaye
        // Jaha woh milenge wahi duplicate number hoga
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];   // ek step
            ptr2 = nums[ptr2];   // ek step
        }

        // Step 5: Return the duplicate number
        return ptr1;
    }
};
