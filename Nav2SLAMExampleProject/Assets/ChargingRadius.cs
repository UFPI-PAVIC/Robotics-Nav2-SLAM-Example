using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.Std;
using RosMessageTypes.Visualization;
using RosMessageTypes.Geometry;
using RosMessageTypes.CustomInterfaces;

public class ChargingRadius : MonoBehaviour
{ 
    public GameObject IoTDevice;
    public string IsRechargingTopic = "/iot_charging_in_range";
    public string NotRechargingTopic = "/iot_charging_not_in_range";
    ROSConnection c_Ros;
    Renderer renderer;

    void Awake(){
        IsRechargingTopic = "iot_" + IoTDevice.name[IoTDevice.name.Length-1] + "/" +IsRechargingTopic;
        NotRechargingTopic = "iot_" + IoTDevice.name[IoTDevice.name.Length-1] + "/" + NotRechargingTopic;
    }
    // Start is called before the first frame update
    void Start()
    {
        c_Ros = ROSConnection.GetOrCreateInstance();
        c_Ros.Subscribe<IotDeviceRequestMsg>(IsRechargingTopic, RechargingFunction);
        c_Ros.Subscribe<IotDeviceRequestMsg>(NotRechargingTopic, IsNotRechargingFunction);
        renderer = GetComponent<Renderer>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void RechargingFunction(IotDeviceRequestMsg msg){
        Color color = Color.green;
        color.a = 0.3f;


        renderer.material.color = color;
    }
    void IsNotRechargingFunction(IotDeviceRequestMsg msg){
        Color color = Color.yellow;
        color.a = 0.3f;


        renderer.material.color = color;
    }
}
