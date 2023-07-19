using System;
using System.IO;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Net;


namespace RestApis
{
    class csharp {

        static void Main(string[] args){

            Console.WriteLine("Hi");
            WebRequest request = WebRequest.Create ("https://jsonmock.hackerrank.com/api/transactions");
            //request.Credentials = CredentialCache.DefaultCredentials;
            HttpWebResponse response = (HttpWebResponse)request.GetResponse ();
            Stream dataStream = response.GetResponseStream ();
            StreamReader reader = new StreamReader (dataStream);
            string responseFromServer = reader.ReadToEnd ();
            Console.WriteLine (responseFromServer);
            reader.Close(); dataStream.Close(); response.Close();
        }    


    }   





}