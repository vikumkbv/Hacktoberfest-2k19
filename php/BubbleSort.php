<?php
/**
 * Bubble sort implementation
 * @see https://en.wikipedia.org/wiki/Bubble_sort for more information
 * @license MIT
 * @author May (MayMeow) https://github.com/MayMeow
 */

/**
 * Class BubbleSort
 */
 class BubbleSort
 {
     /**
      * @var bool $swapped Set true if you have swapped array items
      */
     protected $swapped = true;

     /**
      * @var array $data Data to sort
      */
     protected $data;

     /**
      * @var int $dataSize Size of data to sort
      */
     protected $dataSize;

     /**
      * @var null $temp Using this for store items which need to be swapped
      */
     protected $temp = null;

     /**
      * BubbleSort constructor.
      * @param array $data
      */
     public function __construct(array $data)
     {
         $this->data = $data;
         $this->dataSize = count($data);
     }

     /**
      * Method sort
      * @return array
      */
     public function sort()
     {
         while($this->swapped) {
             $this->swapped = false;

             for ($i = 0; $i < $this->dataSize -1; $i++) {
                 if ($this->data[$i] > $this->data[$i+1]) {
                     $this->_swap($i);
                     $this->swapped = true;
                 };
             }
         }

         return $this->data;
     }

     /**
      * Method swap
      * @param $i
      */
     protected function _swap($i)
     {
        $this->temp = $this->data[$i];
        $this->data[$i] = $this->data[$i+1];
        $this->data[$i+1] = $this->temp;
     }
 }

 /**
  * Esample
  */

  $data = [1,5,99,189,9,7,4,47,146,8,3,2,6,987];

  $bSort = new BubbleSort($data);
  var_dump($bSort->sort());
