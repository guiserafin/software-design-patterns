import java.util.Stack;

interface Command{

    public void execute();
    public void undo();

}

class NoCommand implements Command{

    public void execute(){
        //nao faz nada
    }

    public void undo(){}

}

//Comandos de cada classe de dispositivo

class LightOnCommand implements Command{

    private Light light;

    public LightOnCommand(Light light){
        this.light = light;
    }

    public void execute() {
        light.on();
    }

    public void undo() {
        light.off();
    }

}

class LightOffCommand implements Command{

    private Light light;

    public LightOffCommand(Light light) {
        this.light = light;
    }

    public void execute() {
        light.off();
    }

    public void undo() {
        light.on();
    }

}

class CeillingFanHighSpeedCommand implements Command{

    private CeillingFan fan;

    public CeillingFanHighSpeedCommand(CeillingFan fan){
        this.fan = fan;
    }

    public void execute(){
        switch (fan.getSpeed()) {
            case 0:
                fan.lowSpeed();
                break;
            case 1:
                fan.mediumSpeed();
                break;
        
            case 2:
                fan.highSpeed();
                break;

            case 3:
                fan.lowSpeed();
                break;
        }
    }

    public void undo(){
        switch (fan.getSpeed()) {
            case 0:
                fan.lowSpeed(); //pegar a velocidade anterior
                break;
            case 1:
                fan.off();
                break;
        
            case 2:
                fan.lowSpeed();
                break;

            case 3:
                fan.mediumSpeed();
                break;
        }
    }

}

class CeillingFanOffCommand implements Command{
    private CeillingFan fan;

    public CeillingFanOffCommand(CeillingFan fan){
        this.fan = fan;
    }

    public void execute() {
        fan.off();
    }

    public void undo(){
        fan.lowSpeed();
    }
}

class GarageDoorUpCommand implements Command{
    private GarageDoor door;

    public GarageDoorUpCommand(GarageDoor porta) {
        this.door = porta;
    }

    public void execute() {
        door.up();
    }

    public void undo() {
        door.down();
    }
    
}

class GarageDoorDownCommand implements Command{
    private GarageDoor door;

    public GarageDoorDownCommand(GarageDoor porta){
        this.door = porta;
    }

    public void execute() {
        door.down();
    }

    public void undo() {
        door.up();
    }
    
}

class StereoOnWithCDCommand implements Command{
    private Stereo stereo;

    public StereoOnWithCDCommand(Stereo radio) {
        this.stereo = radio;
    }

    public void execute(){
        stereo.setCD();
        stereo.on();
    }

    public void undo(){
        stereo.off();
    }
}

class StereoOffCommand implements Command{
    private Stereo stereo;

    public StereoOffCommand(Stereo radio) {
        this.stereo = radio;
    }

    public void execute() {
        stereo.off();
    }

    public void undo(){
        stereo.on();
    }
}

//Implementacao das classes de dispositivos
class Light{

    private String comodo;

    public Light(String comodo){
        this.comodo = comodo;
    }

    public void on() {
        System.out.println("Luz ligada - " + comodo);
    }

    public void off() {
        System.out.println("Luz desligada - " + comodo);
    }
}

class CeillingFan{

    private int speed;

    public void highSpeed(){
        this.speed = 3;
        System.out.println("Ventilador em velocidade alta");
    }

    public void mediumSpeed(){
        this.speed = 2;
        System.out.println("Ventilador em velocidade media");

    }

    public void lowSpeed(){
        this.speed = 1;
        System.out.println("Ventilador em velocidade baixa");

    }

    public int getSpeed(){
        return this.speed;
    }

    public void off(){
        this.speed = 0;
        System.out.println("Ventilador desligado");

    }

}

class GarageDoor{

    public void up(){
        System.out.println("Porta da garagem subindo...");
    }

    public void down(){
        System.out.println("Porta da garagem descendo...");
    }

}

class Stereo{

    private String mode;
    private int volume;

    public void on() {
        System.out.println("Aparelho de som ligado");
    }

    public void off() {
        System.out.println("Aparelho de som desligado");
    }

    public void setCD(){
        this.mode = "cd";
        System.out.println("Aparelho de som no modo " + mode);
    }

    public void setDVD(){
        this.mode = "dvd";
        System.out.println("Aparelho de som no modo " + mode);
    }

    public void setRadio() {
        this.mode = "radio";
        System.out.println("Aparelho de som no modo" + mode);
    }

    public void setVolume(int vol){
        this.volume = vol;
        System.out.println("Volume em " + this.volume);
    }

    public String getMode(){
        return this.mode;
    }
}

class RemoteControl {

    private Command[] onCommands;
    private Command[] offCommands;
    private Stack<Command> historico =  new Stack<>();

    public RemoteControl() {
        onCommands = new Command[7];
        offCommands = new Command[7];

        for (int i = 0; i < 7; i++) {
            onCommands[i] = new NoCommand();
            offCommands[i] = new NoCommand();
        }
    }

    public void setCommand(int slot, Command comando, Command offCommand){
        onCommands[slot] = comando;
        offCommands[slot] = offCommand;
    }

    public void onButtonWasPushed(int slot){
        onCommands[slot].execute();
        historico.push(onCommands[slot]);
    }

    public void offButtonWasPushed(int slot){
        offCommands[slot].execute();
        historico.push(offCommands[slot]);
    }

    public void globalUndo(){
        if (!historico.isEmpty()) {
            Command comandoDesfeito = historico.pop();
            comandoDesfeito.undo();
        }
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Controle Remoto:\n");
        for (int i = 0; i < onCommands.length; i++) {
            stringBuilder.append("Slot ").append(i).append(": ").append(onCommands[i].getClass().getSimpleName()).append("\n");
        }
        return stringBuilder.toString();
    }

}



public class RemoteLoader{

    public static void main(String[] args){

        RemoteControl controle = new RemoteControl();
        
        CeillingFan ventilador = new CeillingFan();
        Light luz = new Light("Sala");
        Light luz2 = new Light("Cozinha");
        Stereo radio = new Stereo();
        GarageDoor porta = new GarageDoor();


        controle.setCommand(0, new LightOnCommand(luz), new LightOffCommand(luz));
        controle.setCommand(1, new LightOnCommand(luz2), new LightOffCommand(luz2));

        controle.setCommand(2, new CeillingFanHighSpeedCommand(ventilador), new CeillingFanOffCommand(ventilador));
        controle.setCommand(3, new StereoOnWithCDCommand(radio), new StereoOffCommand(radio));
        controle.setCommand(4, new GarageDoorUpCommand(porta), new GarageDoorDownCommand(porta));
        System.out.println(controle.toString());

        controle.onButtonWasPushed(0);
        controle.offButtonWasPushed(0);

        controle.onButtonWasPushed(1);
        controle.globalUndo();

        controle.onButtonWasPushed(2);
        ventilador.highSpeed();
        controle.offButtonWasPushed(2);

        controle.onButtonWasPushed(3);

        radio.setVolume(11);

        controle.offButtonWasPushed(3);
    }

}