using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace SmartFeeder.Core
{
    public class Feeder
    {
        private const string CONTROLLER_URL = "http://10.0.201.78/feed";

        public async Task Feed()
        {
            HttpClient client = new HttpClient();
            await client.GetAsync(CONTROLLER_URL);
        }
    }
}
