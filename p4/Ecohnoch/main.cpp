class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if(len1 == 0){
            if(len2 == 0) return -1;
            if(len2 == 1) return nums2[0];

            if(len2 % 2 == 0){
                int indice1 = len2 / 2, indice2 = len2 / 2 - 1;
                return (nums2[indice1] + nums2[indice2]) / 2.0;
            }else{
                int indice = len2 / 2;
                return nums2[indice];
            }
        }
        if(len2 == 0){
            if(len1 == 0) return -1;
            if(len1 == 1) return nums1[0];

            if(len1 % 2 == 0){
                int indice1 = len1 / 2, indice2 = len1 / 2 - 1;
                return (nums1[indice1] + nums1[indice2]) / 2.0;
            }else{
                int indice = len1 / 2;
                return nums1[indice];
            }
        }

        double ans;
        if((len1 + len2) % 2 == 0){
            int indice = (len1 + len2) / 2 - 1;
            int astart = 0, bstart = 0, now = -1, counter = -1;
            double ans2;

            while(astart != len1 && bstart != len2){
                if(nums1[astart] <= nums2[bstart]){
                    now = nums1[astart];
                    astart ++;
                }else{
                    now = nums2[bstart];
                    bstart ++;
                }
                counter += 1;
                if(counter == indice){
                    ans = now;
                }
                if(counter == indice + 1){
                    ans2 = now;
                    ans = (ans + ans2) / 2;
                    return ans;
                }
            }

            if(astart == len1){
                while(counter < indice){
                    counter += 1;
                    ans = nums2[bstart];
                    bstart ++;
                }
                ans2 = nums2[bstart];
                ans = (ans + ans2) / 2;
                return ans;

            }
            if(bstart == len2){
                while(counter < indice){
                    counter += 1;
                    ans = nums1[astart];
                    astart ++;
                }
                ans2 = nums1[astart];
                ans = (ans + ans2) / 2;
                return ans;
            }


        }else{

            int indice = (len1 + len2) / 2;
            int astart = 0, bstart = 0, now = -1, counter = -1;


            while(astart != len1 && bstart != len2){
                if(nums1[astart] <= nums2[bstart]){
                    now = nums1[astart];
                    astart ++;
                }else{
                    now = nums2[bstart];
                    bstart ++;
                }
                counter += 1;
                if(counter == indice){
                    ans = now;
                    return ans;
                }
            }

            if(astart == len1){
                while(counter < indice){
                    counter += 1;
                    ans = nums2[bstart];
                    bstart ++;
                }
                return ans;

            }
            if(bstart == len2){
                while(counter < indice){
                    counter += 1;
                    ans = nums1[astart];
                    astart ++;
                }
                return ans;
            }

        }
        return -1;
    }
};
