module.exports = {
    initSDK: function (name, successCallback, errorCallback) {
    	console.log("B4SSDKHandle");
        cordova.exec(successCallback, errorCallback, "B4SSDK", "init", [name]);
    }
};