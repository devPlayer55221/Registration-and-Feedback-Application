$From = "mukundkedia27@outlook.com"
$To = "aman_kedia2007@yahoo.co.in"
$Subject = "Application Data"
$Body = "[Name = hello from mukund]. [Email ID = the registration application for akash bhaiya]. [Phone no = made from visual studio]. [Serial no = emailing part is done]. [Order no = :):);)]."
$SMTPServer = "smtp-mail.outlook.com"
$SMTPPort = "587"
$User = "mukundkedia27@outlook.com"
$Pword = ConvertTo-SecureString -String "H!a2c3k4e5r6" -AsPlainText -Force
$Credential = New-Object -TypeName System.Management.Automation.PSCredential -ArgumentList $User, $Pword
Send-MailMessage -From $From -to $To -Subject $Subject -Body $Body -SmtpServer $SMTPServer -port $SMTPPort -UseSsl -Credential $Credential -DeliveryNotificationOption OnSuccess
