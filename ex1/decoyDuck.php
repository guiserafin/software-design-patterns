<?php


class decoyDuck extends Duck{

    public function __construct(){

        $this->setFlyBehavior(new flyNoWay());
        $this->setQuackBehavior(new muteQuack());
    }

    public function display()
    {
        echo "Im a duck decoy";
    }

}