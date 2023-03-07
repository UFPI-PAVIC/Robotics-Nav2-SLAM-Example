using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.Std;
using RosMessageTypes.Visualization;
using RosMessageTypes.Geometry;

public class ChargingRadius : MonoBehaviour
{ 
    public GameObject IoTDevice;
    public string IsRechargingTopic = "/iot_charging_in_range";
    public string NotRechargingTopic = "/iot_charging_not_in_range";
    ROSConnection c_Ros;
    Renderer renderer;

    void Awake(){
        IsRechargingTopic = "device_" + IoTDevice.name[-1] + IsRechargingTopic;
        NotRechargingTopic = "device_" + IoTDevice.name[-1] + NotRechargingTopic;
    }
    // Start is called before the first frame update
    void Start()
    {
        c_Ros = ROSConnection.GetOrCreateInstance();
        c_Ros.Subscribe<BoolMsg>(IsRechargingTopic, RechargingFunction);
        c_Ros.Subscribe<BoolMsg>(NotRechargingTopic, IsNotRechargingFunction);
        renderer = GetComponent<Renderer>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void RechargingFunction(BoolMsg msg){
        Color color = Color.green;
        color.a = 0.3f;


        renderer.material.color = color;
    }
    void IsNotRechargingFunction(BoolMsg msg){
        Color color = Color.yellow;
        color.a = 0.3f;


        renderer.material.color = color;
    }
}
