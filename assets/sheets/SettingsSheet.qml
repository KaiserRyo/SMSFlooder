import bb.cascades 1.0
import bb.multimedia 1.0
import bb.cascades.pickers 1.0

Sheet 
{
    id: sheet
    peekEnabled: false
    property bool firstRun : true;
    property bool firstRunTheme : true;

    Page 
    {
        titleBar: TitleBar 
        {
            title: "Settings"
            dismissAction: ActionItem 
            {
                title: "Close"
                imageSource: "asset:///images/close.png"
                onTriggered: 
                {
                    sheet.close();
                }
            }
        }
        
        ScrollView 
        {
            Container 
            {
                topPadding: 20
                leftPadding: 20
                rightPadding: 20
                bottomPadding: 40
                
                Container 
                {
                    horizontalAlignment: HorizontalAlignment.Fill  
                    
                    layout: StackLayout 
                    {
                        orientation: LayoutOrientation.LeftToRight   
                    }
                    
                    ImageView 
                    {
                        imageSource: "asset:///images/lock.png"
                        preferredHeight: 100
                        scalingMethod: ScalingMethod.AspectFit
                    }
                    
                    Header 
                    {
                        title: "APP PASSWORD LOCK"
                        verticalAlignment: VerticalAlignment.Center
                    }
                }
                
                Divider {}
                
                Container 
                {
                    horizontalAlignment: HorizontalAlignment.Fill  
                    
                    layout: DockLayout {}
                    
                    Label
                    {
                        text: "Application Password"  
                    }
                    
                    ToggleButton 
                    {
                        id: passwordEnabled
                        checked: _app.getSetting("appPasswordEnabled", false);
                        horizontalAlignment: HorizontalAlignment.Right
                        onCheckedChanged: {
                            _app.setSetting("appPasswordEnabled", checked);
                        }
                    }
                }
                
                TextField 
                {
                    id: password
                    visible: passwordEnabled.checked
                    inputMode: TextFieldInputMode.Password
                    hintText: "Application Password"
                    text: _app.getSetting("appPassword", "");
                    bottomMargin: 50
                    onTextChanging: {
                        _app.setSetting("appPassword", text);
                    }
                }
                
                Label 
                {
                    text: "This will be the password you will use to unlock " + appname + " when opened. This is different than the triggered unlock password."
                    multiline: true
                    textStyle.fontSize: FontSize.XXSmall
                    textStyle.fontStyle: FontStyle.Italic
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
                        imageSource: "asset:///images/theme.png"
                        preferredHeight: 100
                        scalingMethod: ScalingMethod.AspectFit
                    }
                    
                    Header 
                    {
                        title: "APP COLOR THEME"
                        verticalAlignment: VerticalAlignment.Center
                    }
                }
                
                Divider 
                {
                
                }
                
                DropDown 
                {
                    id: theme
                    title: "Application Color Theme"
                    selectedIndex: (_app.getSetting("colortheme", "dark") == "dark" ? 0 : 1);
                    options: 
                    [
                        Option
                        {
                            text: "Dark"
                            imageSource: "asset:///images/dark.png"
                        },
                        Option
                        {
                            text: "Bright"
                            imageSource: "asset:///images/light.png"
                        }
                    ]
                    
                    onSelectedValueChanged: 
                    {
                        if(!firstRunTheme)
                        {
                            _app.setSetting("colortheme", selectedOption.text.toLowerCase());
                            _app.showDialog("Attention", "Changing Color Theme requires an App Restart.")
                        }
                        
                        firstRunTheme = false; 
                    }
                }
                
                Divider {
                    
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
                        imageSource: "asset:///images/orientauto.png"
                        preferredHeight: 100
                        scalingMethod: ScalingMethod.AspectFit
                    }
                    
                    Header 
                    {
                        title: "PREFFERED APP ORIENTATION"
                        verticalAlignment: VerticalAlignment.Center
                    }
                }
                
                Divider 
                {
                
                }
                
                DropDown 
                {
                    id: orientation
                    title: "Preferred Orientation"
                    selectedIndex: _app.getSetting("orientation", 0);
                    enabled: true
                    options: 
                    [
                        Option
                        {
                            text: "Auto Orient"
                            imageSource: "asset:///images/orientauto.png"
                        },
                        Option
                        {
                            text: "Portrait"
                            imageSource: "asset:///images/orientportrait.png"
                        },
                        Option
                        {
                            text: "Landscape"
                            imageSource: "asset:///images/orientlandscape.png"
                        }
                    ]
                    
                    onSelectedIndexChanged: 
                    {
                        _app.setSetting("orientation", selectedIndex);
                        setOrientation();
                    }
                }
                
                Label {
                    text: "This will lock this App's Screen Orientation to your preferred setting."
                    multiline: true
                    textStyle.fontSize: FontSize.XXSmall
                    textStyle.fontStyle: FontStyle.Italic
                }
                
                
                Divider {}
                
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
                        title: "APP ACTIVITY OPTIONS"
                        verticalAlignment: VerticalAlignment.Center
                    }
                }
                
                Divider {}
                
                Container 
                {
                    horizontalAlignment: HorizontalAlignment.Fill  
                    
                    layout: DockLayout {}
                    
                    Label
                    {
                        text: "Keep Awake"
                    }
                    
                    ToggleButton 
                    {
                        id: keepawake
                        checked: _app.getSetting("keepawake", true);
                        horizontalAlignment: HorizontalAlignment.Right
                        onCheckedChanged: 
                        {
                            _app.setSetting("keepawake", checked);
                            setKeepAwake();
                        }
                    }
                }
                
                Label {
                    text: "This will keep your phone's screen on and will never be locked (only when the app is in focus)"
                    multiline: true
                    textStyle.fontSize: FontSize.XXSmall
                    textStyle.fontStyle: FontStyle.Italic
                }
            } 
        }
    }
    
    onCreationCompleted: 
    {
        setOrientation();
        setKeepAwake();
    }
    
    function setOrientation()
    {
        var orientation = _app.getSetting("orientation", 0);
        
        if(orientation == 0)
        {
            OrientationSupport.supportedDisplayOrientation = 
            SupportedDisplayOrientation.All;  
        }
        else if(orientation == 1)
        {
            OrientationSupport.supportedDisplayOrientation = 
            SupportedDisplayOrientation.DisplayPortrait;  
        }
        else if(orientation == 2)
        {
            OrientationSupport.supportedDisplayOrientation = 
            SupportedDisplayOrientation.DisplayLandscape;  
        }
    }
    
    function setKeepAwake()
    {
        if(_app.getSetting("keepawake", "false") == "true" || _app.getSetting("keepawake", "") == "")
        {
            Application.mainWindow.screenIdleMode = 1;
        }
        else 
        {
            Application.mainWindow.screenIdleMode = 0;
        }
    }
}