using SmartFeeder.Core;
using SmartFeeder.Core.ViewModels;
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

        [HttpPost]
        public IHttpActionResult SetTimer([FromBody]FeedingViewModel model)
        {
            TimeSpan timeSpan = new TimeSpan();

            switch (model.TimeType)
            {
                case "m":
                    timeSpan = TimeSpan.FromMinutes(model.TimeAmount);
                    break;
                case "s":
                    timeSpan = TimeSpan.FromSeconds(model.TimeAmount);
                    break;
                case "h":
                    timeSpan = TimeSpan.FromHours(model.TimeAmount);
                    break;
            }

            Feeder handle = new Feeder();
            handle.AddTimerFeed(timeSpan);

            return Ok();
        }
    }
}
