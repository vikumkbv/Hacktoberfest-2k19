/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let ar = []
    let len = nums1.length + nums2.length
    let half;
  
    if (len % 2 === 0) {
      half = len / 2
    } else {
      half = Math.ceil(len / 2)
    }
    for (let i = 0, r1 = 0, r2 = 0; i <= len; i++) {
      if (r1 >= nums1.length || nums1[r1] > nums2[r2]) ar[i] = nums2[r2++]
      else ar[i] = nums1[r1++]
      if (!nums1[i] && nums1.length === r1) {
        ar = ar.concat(nums2.slice(r2))
        return median(ar, len)
      }
      if (!nums2[i] && nums2.length === r2) {
        ar = ar.concat(nums1.slice(r1))
        return median(ar, len)
      }
      if (half === i) {
        return median(ar, len)
      }
    }
  
    function median(arr, len) {
      if (len % 2 === 0) {
        let half = len / 2
        return median = (arr[half - 1] + arr[half]) / 2
      } else {
        let half = Math.ceil(len / 2)
        return median = arr[half - 1]
      }
    }
  }