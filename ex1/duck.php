<?php

use quackBehavior;

abstract class Duck{

    public quackBehavior $quackBehavior;
    
    public flyBehavior $flyBehavior;

    public function swim(){

    }

    public function display(){
        
    }

    public function performQuack(){
        
    }

    public function performFly(){

    }

    public function setQuackBehavior(){

    }

    public function setFlyBehavior(){

    }


}