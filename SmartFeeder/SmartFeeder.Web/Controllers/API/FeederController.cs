using SmartFeeder.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Threading.Tasks;
using System.Web.Http;

namespace SmartFeeder.Web.Controllers.API
{
    [RoutePrefix("api/feeder")]
    public class FeederController : ApiController
    {
        [HttpGet]
        public async Task<IHttpActionResult> Feed()
        {
            Feeder handle = new Feeder();
            try
            {
                await handle.Feed();
            }
            catch (InvalidOperationException)
            {
                return InternalServerError();
            }

            return Ok();
        }
    }
}
