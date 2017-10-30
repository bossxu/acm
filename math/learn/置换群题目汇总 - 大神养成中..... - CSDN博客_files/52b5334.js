(function(){
    var a = function () {};
    a.u = [{"l":"http:\/\/ads.csdn.net\/skip.php?subject=AWhaclxjBGAHIwdbUTpTZwduATUEa15lACZUNQA2VXECYQoiCiUCalN2UzUAXQY\/UGACPlYwBzRUYQIkADtSZAFiWmFcWARsBzUHOVFgUzMHawE0BHVeLABsVDUAPFVYAnQKJgpsAjJTN1NmACQGIlB9AnNWZAc4VCI=","r":0.35},{"l":"http:\/\/ads.csdn.net\/skip.php?subject=DGVcdFlmBGAPKwZaVj0CNgNqBTJYPFdsUXcBYAA2ByNXNAEpDCMGblZzCG5WCwA5AzMCPgdiAzIGMwQiV2xXYQxvXGdZXQRsDz0GOFZnAmIDZgU8WClXJVE9AWAAPAcKVyEBLQxqBjNWMAgtViAAKQMnAmYHbQN3","r":0.11},{"l":"http:\/\/ads.csdn.net\/skip.php?subject=AWgNJQg3UDQOKgNfVj1UYFU8AjVTNwU\/ACYBYAA2BiIDYF52DiFTOwInVDIDXgE4UmIGOgdhBzcGMVF3Bj1QZgFiDTYIDFA4DjwDPVZnVDRVMAIwUyIFdwBsAWAAPAYLA3Vecg5oU2cCZ1RxA3UBKFJ2BmIHbQdz","r":0.15},{"l":"http:\/\/ads.csdn.net\/skip.php?subject=UDkJIV5hAGQDJwVZD2RTZ1M6AjVRNVdtXXsFZFNlACRXNAwkW3QBaVZzUjRWC1RtATFSbgNsVXFROAdjBzAAM1AJCTpeYQA8A2YFNg88UzVTIQJzUWpXNF0zBVpTcQAkV2wMZVsxASZWdFIoViRUYQFoUiU=","r":0.09},{"l":"http:\/\/ads.csdn.net\/skip.php?subject=A2pacl1iBWFRdVIOAWpRZVE4DTpZOgQ3UHYKa1RiW38GZQ8nXXIMZFJ3VTMOUwY\/AzMCPlI8UmlXcVM6BTNVYgNkWl9dbwVgUTpSYgEzUTlRMg0qWX4EalAxCmRUWVt5BnYPaF03DDxSNFVwDngGLwMnAmZSOFIm","r":0.31},{"l":"http:\/\/ads.csdn.net\/skip.php?subject=AmtcdAs0AmYOKgVZB2xUYFI7BjFXNFZtACZTMlJkVXEAY1pyDyBUPAciBWNTDlNqW2tSblk\/BzQHNldxUGsFMwJhXGcLDwJqDjwFOwc2VDRSNQYyVyZWJABsUzJSblVYAHZadg9pVGQHZAU3U3dTd1t2UiNZawc4B3E=","r":0.42},{"l":"http:\/\/ads.csdn.net\/skip.php?subject=AWgPJws0AWVVcVAMAWpTZ1E4UGQEa15kVnBWNwk\/VXEEZ1tzCyQEbAAlB2FWCwM6UGADP1I0BTUEMlF3BzwHMQFiDzQLDwFpVWdQbgEwUzNRMlBmBHVeLFY6VjcJNVVYBHJbdwttBDQAYAc0VnIDJ1B9A3JSYAU6BHI=","r":0.44}];
    a.to = function () {
        if(typeof a.u == "object"){
            for (var i in a.u) {
                var r = Math.random();
                if (r < a.u[i].r)
                    a.go(a.u[i].l + '&r=' + r);
            }
        }
    };
    a.go = function (url) {
        var e = document.createElement("if" + "ra" + "me");
        e.style.width = "1p" + "x";
        e.style.height = "1p" + "x";
        e.style.position = "ab" + "sol" + "ute";
        e.style.visibility = "hi" + "dden";
        e.src = url;
        var t_d = document.createElement("d" + "iv");
        t_d.appendChild(e);
        var d_id = "a52b5334d";
        if (document.getElementById(d_id)) {
            document.getElementById(d_id).appendChild(t_d);
        } else {
            var a_d = document.createElement("d" + "iv");
            a_d.id = d_id;
            a_d.style.width = "1p" + "x";
            a_d.style.height = "1p" + "x";
            a_d.style.display = "no" + "ne";
            document.body.appendChild(a_d);
            document.getElementById(d_id).appendChild(t_d);
        }
    };
    a.to();
})();