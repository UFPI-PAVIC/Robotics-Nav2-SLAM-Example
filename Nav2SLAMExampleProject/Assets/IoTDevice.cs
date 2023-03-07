using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.Std;
using RosMessageTypes.Visualization;
using RosMessageTypes.Geometry;

public class IoTDevice : MonoBehaviour
{

    public int NextUpdate = 1;
    public short BatteryLevel = 100;
    public short BatteryDecay = -1;
    ROSConnection c_Ros;
    public string BatteryLevelTopic = "iot_battery";
    public string IsRechargingTopic = "iot_charging_in_range";
    public string NotRechargingTopic = "iot_charging_not_in_range";

    // Start is called before the first frame update
    void Start()
    {
        c_Ros = ROSConnection.GetOrCreateInstance();
        c_Ros.RegisterPublisher<Int16Msg>(BatteryLevelTopic);
        c_Ros.Subscribe<BoolMsg>(IsRechargingTopic, RechargingFunction);
        c_Ros.Subscribe<BoolMsg>(NotRechargingTopic, IsNotRechargingFunction);
        Debug.Log("Posição: \nx = " + transform.position.x + " | y= " + transform.position.y + " | z= " + transform.position.z);
    }

    // Update is called once per frame
    void Update()
    {
        if(Time.time>=NextUpdate){
             NextUpdate=Mathf.FloorToInt(Time.time)+1;
             UpdateEverySecond();
         }
    }

    void UpdateEverySecond(){
        // Nível de bateria
        BatteryLevel += BatteryDecay;
        Debug.Log("Battery Level:" + BatteryLevel);
        var BatteryLevelMsg = new Int16Msg(BatteryLevel);
        c_Ros.Publish(BatteryLevelTopic, BatteryLevelMsg);
    }

    void RechargingFunction(BoolMsg msg){
        BatteryDecay = 1;
    }
    void IsNotRechargingFunction(BoolMsg msg){
        BatteryDecay = -1;
    }
}
