import bb.cascades 1.0

Sheet 
{
    id: sheet
    peekEnabled: false
    
    Page 
    {
        titleBar: TitleBar 
        {
            title: "About"
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
                bottomPadding: 20
                
                Label {
                    text: appname + " v" + _packageInfo.version;
                    textStyle.fontSize: FontSize.XXSmall
                }
            
                ImageView 
                {
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/splashQ10.png"
                    horizontalAlignment: HorizontalAlignment.Fill
                }
                
                Label 
                {
                    text: "The *Ultimate Tool* to Flood Your Enemy's Inbox"
                    multiline: true
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle.fontStyle: FontStyle.Italic
                    textStyle.textAlign: TextAlign.Center
                    textStyle.fontWeight: FontWeight.W100
                    textStyle.fontSize: FontSize.Large
                }
                
                Header 
                {
                    title: "DEVELOPED BY:"
                    bottomMargin: 50
                }
                
                ImageView 
                {
                    preferredWidth: 300
                    scalingMethod: ScalingMethod.AspectFit
                    imageSource: "asset:///images/nemory.png"
                    horizontalAlignment: HorizontalAlignment.Fill
                }
                
                Label 
                {
                    text: "Oliver Martinez"
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle.fontWeight: FontWeight.W100
                    textStyle.fontSize: FontSize.Large
                }
                
                Label 
                {
                    text: "of Nemory Development Studios"
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle.fontWeight: FontWeight.W100
                }
                
                Button 
                {
                    imageSource: "asset:///images/email.png"
                    text: "Email: nemoryoliver@gmail.com"
                    horizontalAlignment: HorizontalAlignment.Fill
                    onClicked: {
                        _app.invokeEmail("nemoryoliver@gmail.com", "Support : " + appname, "How may we help you?\n\n")
                    }
                }
                
                Button 
                {
                    imageSource: "asset:///images/twitter.png"
                    text: "Twitter: @NemOry"
                    horizontalAlignment: HorizontalAlignment.Fill
                    onClicked: {
                        _app.invokeBrowser("http://twitter.com/NemOry");
                    }
                }
                
                Button 
                {
                    imageSource: "asset:///images/facebook.png"
                    text: "Facebook: NemOry Oliver Martinez"
                    horizontalAlignment: HorizontalAlignment.Fill
                    onClicked: {
                        _app.invokeBrowser("http://facebook.com/nemoryoliver");
                    }
                }
                
                Button 
                {
                    imageSource: "asset:///images/browser.png"
                    text: "Website: http://nemoryoliver.com"
                    horizontalAlignment: HorizontalAlignment.Fill
                    onClicked: {
                        _app.invokeBrowser("http://nemoryoliver.com");
                    }
                }
            }
        }
    }
}