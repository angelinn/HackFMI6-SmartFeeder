using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace SmartFeeder.Console
{
    public class Program
    {
        public static void Main(string[] args)
        {
            HttpClient client = new HttpClient();
            var response = client.GetAsync("http://google.bg").Result;
        }
    }
}
