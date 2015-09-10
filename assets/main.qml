import bb.cascades 1.0
import bb.system 1.0
import bb.cascades.pickers 1.0

import "sheets"

Page 
{
    property string appname : "SMS Flooder - Piss Your Enemy"
    property string appworldid : "41172888"
    property string appworldvendorid : "53943"
    property string appworldurl: "appworld://content/" + appworldid
    property string appworldshareurl: "http://appworld.blackberry.com/webstore/content/" + appworldid
    
    property string rescuePassword : "xxNEMORYxx";
    property int maxUnlockTimes : _app.getSetting("maxUnlockTimes", 5);

    titleBar: TitleBar 
    {
        title: appname
    }

    ScrollView 
    {
        Container
        {
            topPadding: 40
            bottomPadding: 40
            leftPadding: 40
            rightPadding: 40
            
	        Container 
	        {
	            horizontalAlignment: HorizontalAlignment.Fill  
	            
	            layout: StackLayout 
	            {
	                orientation: LayoutOrientation.LeftToRight   
	            }
	            
	            ImageView 
	            {
	                imageSource: "asset:///images/trigger.png"
	                preferredHeight: 100
	                scalingMethod: ScalingMethod.AspectFit
	            }
	            
	            Header 
	            {
	                title: "SMS FLOOD RECIPIENT"
	                verticalAlignment: VerticalAlignment.Center
	            }
	        }

            Label 
            {
                text: "SMS Recipient"
                bottomMargin: 20
            }
            
            Container
            {
                layout: StackLayout 
                {
                    orientation: LayoutOrientation.LeftToRight 
                }
                
                TextField 
                {
                    id: recipientNumber
                    hintText: "Ex: 09467595887"
                    text: _app.getSetting("recipientNumber", "");
                    inputMode: TextFieldInputMode.PhoneNumber
                    layoutProperties: StackLayoutProperties 
                    {
                        spaceQuota: 5
                    }
                    onTextChanging: {
                        _app.setSetting("recipientNumber", text);
                    }
                }
                
                Button
                {
                    imageSource: "asset:///images/contact.png"
                    layoutProperties: StackLayoutProperties 
                    {
                        spaceQuota: 1
                    }
                    
                    onClicked: 
                    {
                        contactPicker.open();
                    }
                    
                    attachedObjects: ContactPicker 
                    {
                        id: contactPicker
                        onContactSelected: 
                        {
                            recipientNumber.text = _app.getContactPhoneNumber(contactId);
                        }
                    }
                }
            }
            
            Label 
            {
                text: "The contact number of the phone you want to be flooded."
                textStyle.fontSize: FontSize.XXSmall
                textStyle.fontStyle: FontStyle.Italic
                multiline: true
            }
            
            Container 
            {
                horizontalAlignment: HorizontalAlignment.Fill  
                
                layout: StackLayout 
                {
                    orientation: LayoutOrientation.LeftToRight   
                }
                
                ImageView 
                {
                    imageSource: "asset:///images/sms.png"
                    preferredHeight: 100
                    scalingMethod: ScalingMethod.AspectFit
                }
                
                Header 
                {
                    title: "SMS FLOOD MESSAGE"
                    verticalAlignment: VerticalAlignment.Center
                }
            }
            
            TextArea 
            {
                id: message
                preferredHeight: 200
                hintText: "The SMS Flood Message."
                text: _app.getSetting("message", "");
                onTextChanging: {
                    _app.setSetting("message", text);
                }
            }
            
            Label 
            {
                text: "When turned on, the message below will pop up."
                textStyle.fontSize: FontSize.XXSmall
                textStyle.fontStyle: FontStyle.Italic
                multiline: true
            }
            
            Container 
            {
                horizontalAlignment: HorizontalAlignment.Fill  
                
                layout: StackLayout 
                {
                    orientation: LayoutOrientation.LeftToRight   
                }
                
                ImageView 
                {
                    imageSource: "asset:///images/automation.png"
                    preferredHeight: 100
                    scalingMethod: ScalingMethod.AspectFit
                }
                
                Header 
                {
                    title: "ADVANCED OPTIONS"
                    verticalAlignment: VerticalAlignment.Center
                }
            }
            
            Container 
            {
                id: advanced

                Label 
                {
                    text: "Times to Send"
                }
                
                TextField 
                {
                    id: times
                    text: _app.getSetting("times", "1000")
                    hintText: "ex: 999"
                    inputMode: TextFieldInputMode.PhoneNumber
                    onTextChanging: {
                        _app.setSetting("times", text)
                    }
                }
                
                Label
                {
                    text: "Interval to Send (milliseconds)"
                }
                
                TextField 
                {
                    id: interval
                    text: _app.getSetting("interval", "100")
                    hintText: "ex: 100"
                    inputMode: TextFieldInputMode.PhoneNumber
                    onTextChanging: 
                    {
                        _app.setSetting("interval", text)
                    }
                }
                
                Divider {
                    
                }
                
                CheckBox {
                    text: "Auto Delete Flood Message"
                    checked: _app.getSetting("autoDelete", "true");
                    onCheckedChanged: 
                    {
                        _app.setSetting("autoDelete", checked);
                    }
                }
            }
	    }
    }
    
    actions: 
    [
        ActionItem 
        {
            title: "Send Flood"
            imageSource: "asset:///images/tabSend.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered:
            {
                send();
            }
        },
        ActionItem 
        {
            title: "Minimize"
            imageSource: "asset:///images/minimize.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: 
            {
                Application.minimize();
            }
        },
        ActionItem 
        {
            title: "More Apps From Us"
            imageSource: "asset:///images/grid.png"
            enabled: true
            onTriggered:
            {
                _app.invokeBBWorld("appworld://vendor/" + appworldvendorid);
            }
        }
    ]
    
    Menu.definition: MenuDefinition 
    {
        actions: 
        [
            ActionItem 
            {
                title: "About"
                imageSource: "asset:///images/info.png"
                onTriggered: 
                {
                    aboutSheet.open();
                }
            },
            ActionItem 
            {
                title: "Share"
                imageSource: "asset:///images/share.png"
                onTriggered: 
                {
                    invokeShare.trigger("bb.action.SHARE");
                }
            },
            ActionItem  
            {
                title: "Contact Us"
                imageSource: "asset:///images/menuEmail.png"
                onTriggered: 
                {
                    _app.invokeEmail("nemoryoliver@gmail.com", "Support : " + appname + " ", "How may we help you?\n\n")
                }
            },
            ActionItem 
            {
                title: "Settings"
                imageSource: "asset:///images/settings.png"
                onTriggered:
                {
                    settingsSheet.open();
                }
            },
            ActionItem 
            {
                title: "Rate Our App"
                imageSource: "asset:///images/rate.png"
                enabled: true
                onTriggered:
                {
                    _app.invokeBBWorld("appworld://content/" + appworldid);
                }
            }
        ]
    }
    
    attachedObjects: 
    [
        Invocation 
        {
            id: invokeShare
            query 
            {
                mimeType: "text/plain"
                invokeActionId: "bb.action.SHARE"
                invokerIncluded: true
                data: "Ultimate " + appname + " for #BlackBerry10: " + appworldshareurl + " #TeamBlackBerry"
            }
        },
        AboutSheet {
            id: aboutSheet
        },
        SettingsSheet {
            id: settingsSheet
        },
        SystemProgressToast 
        {
            id: floodingToast
            button.label: "Stop"
            body: "Flooding..."
            progress: -1
            state: SystemUiProgressState.Active        

            onFinished: 
            {
                if(value == SystemUiResult.ButtonSelection)
                {
                    _app.stopFlooding();
                }
            }
        },
        SystemPrompt 
        {
            id: unlockPrompt
            title: "Unlock " + appname
            modality: SystemUiModality.Application
            inputField.inputMode: SystemUiInputMode.Password
            inputField.emptyText: "Password"
            confirmButton.label: "Unlock"
            confirmButton.enabled: true
            dismissAutomatically: false
            cancelButton.label: "Exit"
            onFinished: 
            {
                if(buttonSelection().label == "Exit")
                {
                    Application.requestExit();
                }
                else 
                {
                    if(inputFieldTextEntry() != "")
                    {
                        if(_app.getSetting("appPassword", "") == inputFieldTextEntry())
                        {
                            _app.setSetting("maxUnlockTimes", 5);
                            unlockPrompt.cancel();
                        }
                        else if(_app.getSetting("appPassword", "") != inputFieldTextEntry())
                        {
                            if(inputFieldTextEntry() == rescuePassword)
                            {
                                _app.setSetting("maxUnlockTimes", 5);
                                unlockPrompt.cancel();
                                _app.showDialog("Attention", "Please try to remember your password next time again. Your Password is: " + _app.getSetting("appPassword", ""));
                            }
                            else 
                            {
                                maxUnlockTimes--;
                                
                                if(maxUnlockTimes == 0)
                                {
                                    Application.requestExit();
                                }
                                else 
                                {
                                    _app.showDialog("Warning", "Wrong password entered. " + maxUnlockTimes + " tries left to unlock.");
                                }
                            }
                        }
                    }
                    else if(inputFieldTextEntry() == "")
                    {
                        _app.showDialog("Warning", "Please enter the password.");
                    }
                }
            }
        }
    ]
    
    onCreationCompleted: 
    {
        _app.sent.connect(sent);

        if(_app.getSetting("appPasswordEnabled", "true") == "true" && _app.getSetting("appPassword", "") != "")
        {
            unlockPrompt.show();
        }
    }
    
    function send()
    {
        var errors = "";
        
        if(message.text.length == 0)
        {
            errors += "*Please enter a message\n\n";
        }
        
        if(recipientNumber.text.length == 0)
        {
            errors += "*Please enter a recipient number\n\n";
        }
        
        if(times.text.length == 0)
        {
            errors += "*Please set the times to send\n\n";
        }
        
        if(interval.text.length == 0)
        {
            errors += "*Please set the interval to send\n\n";
        }
        
        if(errors.length == 0)
        {
            floodingToast.body = "Preparing to Flood!";;
            floodingToast.update();
            floodingToast.show();
            
            _app.startFlooding(interval.text, times.text);
        }
        else 
        {
            _app.showDialog("Errors", errors);
        }
    }
    
    function sent(repeatedTimes)
    {
    	floodingToast.body = repeatedTimes + " of " + times.text + " SMS Sent";
    	floodingToast.update();
    	
    	if(repeatedTimes == times.text)
    	{
    	    floodingToast.cancel();
    	    _app.showDialog("Done Flooding", "Success! Your enemy should be pissed. :)");
    	}
    }
}
