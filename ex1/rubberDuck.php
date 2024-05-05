<?php


class decoyDuck extends Duck{

    public function __construct(){

        $this->setFlyBehavior(new flyNoWay());
        $this->setQuackBehavior(new squeack());
    }

    public function display()
    {
        echo "Im a rubber decoy";
    }

}