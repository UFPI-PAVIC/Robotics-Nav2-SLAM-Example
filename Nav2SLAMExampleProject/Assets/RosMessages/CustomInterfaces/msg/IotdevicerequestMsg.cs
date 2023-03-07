//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.CustomInterfaces
{
    [Serializable]
    public class IotdevicerequestMsg : Message
    {
        public const string k_RosMessageName = "custom_interfaces/Iotdevicerequest";
        public override string RosMessageName => k_RosMessageName;

        public short iot_id;

        public IotdevicerequestMsg()
        {
            this.iot_id = 0;
        }

        public IotdevicerequestMsg(short iot_id)
        {
            this.iot_id = iot_id;
        }

        public static IotdevicerequestMsg Deserialize(MessageDeserializer deserializer) => new IotdevicerequestMsg(deserializer);

        private IotdevicerequestMsg(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.iot_id);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.iot_id);
        }

        public override string ToString()
        {
            return "IotdevicerequestMsg: " +
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