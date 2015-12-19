using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(SmartFeeder.Web.Startup))]
namespace SmartFeeder.Web
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
