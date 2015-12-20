using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SmartFeeder.Core.ViewModels
{
    public class FeedingViewModel
    {
        public IEnumerable<string> History { get; set; }
        public int TimeAmount { get; set; }
        public string TimeType { get; set; }
    }
}
