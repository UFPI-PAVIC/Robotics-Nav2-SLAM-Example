using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.Std;
using RosMessageTypes.Visualization;
using RosMessageTypes.Geometry;
using RosMessageTypes.CustomInterfaces;

public class IoTDevice : MonoBehaviour
{

    public int NextUpdate = 1;
    public short BatteryLevel = 100;
    public short BatteryDecay = -1;
    public short IoTDeviceId;
    ROSConnection c_Ros;
    public string BatteryLevelTopic = "iot_battery";
    public string IsRechargingTopic = "iot_charging_in_range";
    public string NotRechargingTopic = "iot_charging_not_in_range";

    // Start is called before the first frame update
    void Awake(){
        IoTDeviceId = (short)char.GetNumericValue((gameObject.name[gameObject.name.Length - 1]));
        BatteryLevelTopic = "iot_" + IoTDeviceId.ToString() + "/" + BatteryLevelTopic;
        IsRechargingTopic = "iot_" + IoTDeviceId.ToString() + "/" + IsRechargingTopic;
        NotRechargingTopic = "iot_" + IoTDeviceId.ToString() + "/" + NotRechargingTopic;
    }
    void Start()
    {
        c_Ros = ROSConnection.GetOrCreateInstance();
        c_Ros.RegisterPublisher<IotBatteryMsg>(BatteryLevelTopic);
        c_Ros.Subscribe<IotDeviceRequestMsg>(IsRechargingTopic, RechargingFunction);
        c_Ros.Subscribe<IotDeviceRequestMsg>(NotRechargingTopic, IsNotRechargingFunction);
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
  
        var BatteryLevelMsg = new IotBatteryMsg();
        BatteryLevelMsg.battery_level = BatteryLevel;
        BatteryLevelMsg.iot_id = (short)IoTDeviceId;

        c_Ros.Publish(BatteryLevelTopic, BatteryLevelMsg);
    }

    void RechargingFunction(IotDeviceRequestMsg msg){
        BatteryDecay = 1;
    }
    void IsNotRechargingFunction(IotDeviceRequestMsg msg){
        BatteryDecay = -1;
    }
}
