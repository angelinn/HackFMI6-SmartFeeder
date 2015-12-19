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
        private const string CONTROLLER_URL = "";

        public async Task Feed()
        {
            HttpClient client = new HttpClient();
            await client.GetAsync(CONTROLLER_URL + "?feed=1");
        }
    }
}
