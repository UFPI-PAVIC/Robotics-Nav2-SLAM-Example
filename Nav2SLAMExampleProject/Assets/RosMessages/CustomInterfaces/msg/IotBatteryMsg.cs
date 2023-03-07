//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.CustomInterfaces
{
    [Serializable]
    public class IotBatteryMsg : Message
    {
        public const string k_RosMessageName = "custom_interfaces/IotBattery";
        public override string RosMessageName => k_RosMessageName;

        public short battery_level;
        public short iot_id;

        public IotBatteryMsg()
        {
            this.battery_level = 0;
            this.iot_id = 0;
        }

        public IotBatteryMsg(short battery_level, short iot_id)
        {
            this.battery_level = battery_level;
            this.iot_id = iot_id;
        }

        public static IotBatteryMsg Deserialize(MessageDeserializer deserializer) => new IotBatteryMsg(deserializer);

        private IotBatteryMsg(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.battery_level);
            deserializer.Read(out this.iot_id);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.battery_level);
            serializer.Write(this.iot_id);
        }

        public override string ToString()
        {
            return "IotBatteryMsg: " +
            "\nbattery_level: " + battery_level.ToString() +
            "\niot_id: " + iot_id.ToString();
        }

#if UNITY_EDITOR
        [UnityEditor.InitializeOnLoadMethod]
#else
        [UnityEngine.RuntimeInitializeOnLoadMethod]
#endif
        public static void Register()
        {
            MessageRegistry.Register(k_RosMessageName, Deserialize);
        }
    }
}