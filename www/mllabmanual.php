<?php
session_start();

require("mysql_util.php");
require("css_util.php");
require("mllabhead.php");
require("mllabbody.php");

$gFigLinkIndex=0;
$gFigLink=NULL;

$gStepIndex=0;
$gSteps=NULL;

function getFigureIndex($figLink)
{
	global $gFigLink, $gFigLinkIndex;
	$figIndex=FALSE;
	if(isset($gFigLink))
	{
		foreach($gFigLink as $key => $value)
		{
			if($key == $figLink)
			{
				$figIndex=$value;
				break;
			}
		}
	}
	
	if($figIndex == FALSE)
	{
		$gFigLinkIndex = $gFigLinkIndex + 1;
		$gFigLink[$figLink]=$gFigLinkIndex;
		$figIndex=$gFigLinkIndex;
	}
	return $figIndex;
}

function getStepIndex($stepLabel)
{
	global $gSteps, $gStepIndex;
	$stepIndex=NULL;
	if(isset($gSteps))
	{
		foreach($gSteps as $key => $value)
		{
			if($key == $stepLabel)
			{
				$stepIndex=$value;
				break;
			}
		}
	}
	if($stepIndex == FALSE)
	{
		$gStepIndex=$gStepIndex + 1;
		$gSteps[$stepLabel]=$gStepIndex;
		$stepIndex=$gStepIndex;
	}
	return $stepIndex;
}

function markup_figureLink($figLink)
{
	$figIndex=getFigureIndex($figLink);
	return "<a href=\"#figure " . $figIndex . "\" class=\"yellow-text-underline\">figure " . $figIndex . "</a>";
}

function markup_figureImg($figLink, $figCaption)
{
	$figIndex=getFigureIndex($figLink);
	return "<a name=\"figure" . $figIndex . "\" ><center><img src=\"images/" . $figLink . "\" title=\"figure " . $figIndex . "\" /><br />figure " . $figIndex . ": " . $figCaption . "</center></a>";
}

function markup_stepTitle($stepLabel, $stepCaption)
{
	return "<hr /><a name=\"" . $stepLabel . "\" /><h3>Step " . getStepIndex($stepLabel) . ": " . $stepCaption . "</h3></a><hr />";
}

function markup_stepLink($stepLabel)
{
	$stepIndex=getStepIndex($stepLabel);
	return "<a href=\"#" . $stepLabel . "\" class=\"yellow-text-underline\">step " . $stepIndex . "</a>";
}

function markup_link($url, $name)
{
	return "<a href=\"" . $url . "\" class=\"yellow-text-underline\">" . $name . "</a>";
}

$loginStatus=false;

if(isset($_SESSION['username']))
{
	$loginStatus=true;
}

if($loginStatus==true)
{
	mllabhead("");
	echo "<body>";
	$content="<div style=\"font-size:12px\">";
	$content=$content . "<p>This is a quick tutorial that walks the user through how to <strong>configure, generate</strong> bot script (using MLP as an example) and <strong>create, compete</strong> to test the bot with the user-generated script embeded</p>";
	$content=$content . markup_stepTitle("downloadAndInstallMLLab", "Download and Install MLLab");
	$content=$content . "<p>Click " . markup_link("mllabdownload.php", "MLLab Download") . " link to download the MLLab application and MLLab pdf manual. After downloading the application, double click to launch the installation wizard (as shown in " . markup_figureLink("figure01.gif") . "), follow the default steps (by just clicking the <i>Next</i> button) and complete the installation.<br />";
	$content=$content . markup_figureImg("figure01.gif", "Installation Wizard") . "</p>";
	$content=$content . markup_stepTitle("launchMLLab", "Launch MLLab");
	$content=$content . "<p>";
	$content=$content . "Click MLLab from Windows Program menu to launch MLLab, " . markup_figureLink("figure02.gif") . " shows the <strong>MLLab configuration dialog</strong> on launch.<br />";
	$content=$content . markup_figureImg("figure02.gif", "MLLab Configuration dialog");
	$content=$content . "With the default settings in the dialog, Click <strong>OK</strong> button to launch <strong>MLLab Integrated Development Environment (IDE)</strong> as shown in " . markup_figureLink("figure03.gif") . "</a><br /><br />";
	$content=$content . markup_figureImg("figure03.gif", "MLLab IDE");
	$content=$content . "When the <strong>MLLab IDE</strong> is launched, the 3D scene that user will see is called <strong>Code Design</strong> scene (as indicated by the caption in the lower left as well as the tick placed next to <strong>Scenes-->Code Design</strong> in the main menu of MLLab IDE). The 3D scene can be viewed from different angle using the <strong>LEFT, RIGHT, UP, DOWN</strong> keys on your key board, or can be zoomed in or out using <strong>A, S</strong> on your keyboard. Notice that in <strong>Computational Intelligence</strong> panel at the upper right corner of <strong>MLLab IDE</strong>, the default <strong>Type</strong> read \"Artificial Neural Network\" and the default <strong>Method</strong> read \"Multiple Layer Perceptron\". This indicates that in the next step, the bot script created will be a type of Artificial Neural Network known as Multiple Layer Perceptron (MLP). <br />";
	$content=$content . "</p>";
	$content=$content . markup_stepTitle("PlayGame", "Play a game to capture player data");
	$content=$content . "<p>";
	$content=$content . "When the bot script is going to based on a machine learning algorithm such as MLP, it requires a training data set. We need to obtain the training data from the MLLab simulation environment. To create an MLLab simulation environment, select <strong>Scenes-->Game Design</strong> from the main menu of MLLab IDE. " . markup_figureLink("figure07.gif") . " shows the <strong>Game Design</strong> scene. In <strong>Game Design</strong> scene, apart from the keyboard camera maneurvering descirbed in " . markup_stepLink("launchMLLab") . ", user can also traversing the 3D landscape by holding down right-mouse and draging<br />";
	$content=$content . markup_figureImg("figure07.gif", "Game Design Scene") . "<br />";
	$content=$content . "In the <strong>Game Design</strong> scene, user can perform different task such as: <ul><li>Create Agent<li>Select Agent<li>Simulate</ul>To change from one task to another, select the task from the <strong>Game Design</strong> panel. To record user generated game playing as training data, two tasks are performed: <br /><br />";
	$content=$content . "<table ><tr><td style=\"valign:middle; background-color:#000000;color:#00ff00\"><strong>-->Create Agent:</strong></td>";
	$content=$content . "<tr><td><ol><li>Select <strong>Create Agent</strong> in the <strong>Game Design Commands</strong> panel(default) <li>Generate a set of different bots: select a bot script from the <strong>Bot Loaded</strong> panel in the upper left, and then click on the 3D terrain to generate a bot using that bot script (do not select to generate <strong>UserBot</strong> yet). " . markup_figureLink("figure08.gif") . " shows the bots generated using different scripts from the <strong>Bot Loaded</strong> panel. <br /><br />";
	$content=$content . markup_figureImg("figure08.gif", "Bots generated using various Bot scripts") . "<br />";
	$content=$content . "In " . markup_figureLink("figure08.gif") . ", the popup property dialog is displayed next the selected bot, whenever user right click on a bot. To close the property dialog, right click again on the bot. <br />";
	$content=$content . "<li>Generate a <strong>UserBot</strong>: Select <strong>UserBot</strong> from the <strong>Bot Loaded</strong> panel, and click on the terrain to generate a <strong>UserBot</strong>. A <strong>UserBot</strong> is different from other bots in that the user has total control over its behavior during the game play simulation, which will be illustrated later<br >";
	$content=$content . "</ol></td></tr>";
	$content=$content . "<tr><td style=\"valign:middle; background-color:#000000;color:#00ff00\"><strong>-->Simulate</strong></td></tr>";
	$content=$content . "<tr><td><ol><li>With the generated <strong>UserBot</strong> bot selected in the 3D terrain, select <strong>Simulate</strong> in the <strong>Game Design Commands</strong> panel. " . markup_figureLink("figure10.gif") . " shows the <strong>Game Design</strong> in with the <strong>UserBot</strong> bot selected under the <strong>Simulate</strong> task <br /><br />";
	$content=$content . markup_figureImg("figure10.gif", "Simulate UserBot") . "<br />";
	$content=$content . "Notice that the popup dialog over the selected <strong>UserBot</strong> bot whose title reads \"Action State: Paused\", this indicate that the current simulate scene is paused, under paused action state, the user can examine the environment around the <strong>UserBot</strong> and make appropriate decisions such as whether to attack or escape from which enemy, under the user make appropriate choice, click on the <strong>Continue</strong> button to activate the simulation. " . markup_figureLink("figure11.gif") . " shows the game under simulation. <br /><br />";
	$content=$content . markup_figureImg("figure11.gif", "UserBot in simulation") . "<br />";
	$content=$content . "The user is in charge of the action performed the <strong>UserBot</strong>, and whenever the user feel the need to pause the game, he can click on the <strong>Pause</strong> button. During the active simulation, the user's control of <strong>UserBot</strong> as well as the surrounding of <strong>UserBot</strong> is monitored and recorded in MLLab as training data.";
	$content=$content . "The user can also get a better feel on the current situation of the <strong>UserBot</strong> bot by launching a browser that will display various statistical information around surrounding of the <strong>UserBot</strong> bot as well as its current conditions. To launch the browser, select <strong>Toolkits-->Web Browser</strong> from the main menu of MLLab IDE. " . markup_figureLink("figure19.gif") . " shows the browser after its launch. The transparency of the browser can be tuned through its slider bar and the browser can be moved around by right-pressing the browser and draging</p>";
	$content=$content . markup_figureImg("figure19.gif", "<strong>UserBot</strong> bot statistics displayed in browser") . "<br />";
	$content=$content . "</ol></td></tr>";
	$content=$content . "</table>";
	$content=$content . "</p>";
	$content=$content . markup_stepTitle("CreateConfigureBotScript", "Create and Configure Bot script (MLP as an example)");
	$content=$content . "<p>";
	$content=$content . "Let's go back to the default <strong>Code Design</strong> scene by selecting <strong>Scenes-->Code Design</strong> from the main menu of MLLab IDE. Now in the <strong>Code Design</strong>, with <strong>Type</strong>=\"Artificial Neural Network\"(default) and <strong>Method</strong>=\"Multiple Layer Perceptron\" in the <strong>Computational Intelligence</strong> panel, left-click any place on the 3D terrain to generate a robot as shown in " . markup_figureLink("figure04.gif") . ". This robot will represent an instance of MLP bot script that the user is to configure and generate.<br />";
	$content=$content . markup_figureImg("figure04.gif", "MLP script represented by the robot");
	$content=$content . "With the robot selected (indicated by the white bounding box), click <strong>Configure</strong> button at the bottom <strong>command bar</strong> of <strong>MLLab IDE</strong>. This will activate the MLP bot <strong>script configuration</strong> dialog as shown in " . markup_figureLink("figure05.gif") . "<br />";
	$content=$content . markup_figureImg("figure05.gif", "MLP script configuration dialog on the robot") . "<br />";
	$content=$content . "The <strong>script configuration</strong> dialog allows user to specify network parameters, training procedures, and hidden layer structures, proceed to specify those configurations before click <strong>OK</strong> button to save the configurations. After this step, the robot will now has the knowledge of the user-configured MLP.<br />";
	$content=$content . "</p>";
	$content=$content . markup_stepTitle("GenerateBotScript", "Generate Bot script (MLP as an example)");
	$content=$content . "<p>";
	$content=$content . "With the MLP configured in " . markup_stepLink("CreateConfigureBotScript") . ", now it is time to generate this configured MLP as the bot script. To do this, with the robot selected, click <strong>Generate Code</strong> button at the bottom <strong>command bar</strong>. This will launch the <strong>Code Generator</strong> dialog as shown in " . markup_figureLink("figure06.gif") . "<br />";
	$content=$content . markup_figureImg("figure06.gif", "Code Generator for generating the configured MLP") . "<br />";
	$content=$content . "Click <strong>Browse</strong> to select a folder in the local computer to store the generated source code. With <strong>lua</strong> as the programming language for the generated code (default), click <strong>Generate</strong> button. Note that when the lua source code is generated in the user-selected folder, the training data previously obtained in " . markup_stepLink("PlayGame") . " is also exported into the folder with the name data.lua";
	$content=$content . "</p>";
	$content=$content . markup_stepTitle("CreateTrainBot", "Import and Train Bot (MLP as an example)");
	$content=$content . "<p>For advanced user, you might want to study the generated MLP Bot script to understand how it works, and modify some of the codes to increase the Bot's efficiency. On the other hand, the default generated Bot script will work without any need for modification when it is imported into the <strong>Game Design</strong> scene of the <strong>MLLab IDE</strong> (refer to " . markup_stepLink("PlayGame") . " for more details of <strong>Game Design</strong> scene). The following steps explains how to import and train the MLP bot obtained in " . markup_stepLink("CreateConfigureBotScript") . " and " . markup_stepLink("GenerateBotScript") . "<br /><br />";
	$content=$content . "<ol><li>Switch to <strong>Game Design</strong> scene by selecting <strong>Scenes-->Game Design</strong> from the main menu of MLLab IDE";
	$content=$content . "<li>Select <strong>Create Agent</strong> in the <strong>Game Design Commands</strong> panel";
	$content=$content . "<li>Click <strong>Import Script</strong> in the <strong>Bot Loaded</strong> panel, an <strong>Add Bot</strong> dialog will pop up as shown in " . markup_figureLink("figure12.gif") . "<br />";
	$content=$content . "<li>Click the <strong>Browse</strong> button in the <strong>Add Bot</strong> dialog. In the Folder Selection dialog, select the folder in which the generated MLP script obtained in "  . markup_stepLink("CreateConfigureBotScript") . " and " . markup_stepLink("GenerateBotScript") . " are stored";
	$content=$content . "<li>Enter a name for the bot script (\"LaBot\" for example) and press <strong>AddBot</strong> button to import the bot script created in " .  markup_stepLink("CreateConfigureBotScript") . " and " . markup_stepLink("GenerateBotScript") . ". You should now see that \"LaBot\" now appear in the <strong>Bot Loaded</strong> panel as shown in " . markup_figureLink("figure13.gif") . "";
	$content=$content . "<li>Create a <strong>LaBot</strong> bot by selecting <strong>LaBot</strong> in the <strong>Bot Loaded</strong> panel and clicking on the 3D terrain. Now right-click the created <strong>LaBot</strong> bot, and a property dialog for the <strong>LaBot</strong> bot pop as shown in " . markup_figureLink("figure14.gif");
	$content=$content . "<li>To train the <strong>LaBot</strong> bot using the training data generated in " . markup_stepLink("PlayGame") . ", click on <strong>Train</strong> button in the popup property dialog of <strong>LaBot</strong> bot. This will launch the console window which displays the traing process as shown in " . markup_figureLink("figure15.gif");
	$content=$content . "</ol>";
	$content=$content . markup_figureImg("figure12.gif", "Add Bot dialog") . "<br />";
	$content=$content . markup_figureImg("figure13.gif", "Bot Script Imported") . "<br />";
	$content=$content . markup_figureImg("figure14.gif", "Popup Property page for the <strong>LaBot</strong> bot") . "<br />";
	$content=$content . markup_figureImg("figure15.gif", "Training process for the <strong>LaBot</strong> bot") . "<br />";
	$content=$content . markup_stepTitle("SimulateCompete", "Simulate Bot Competitency (MLP as an example)");
	$content=$content . "<p>Now that everything is ready, we can test the performance of a <strong>LaBot</strong> when compete with other bots during the actual simulation. Perform the following steps:";
	$content=$content . "<ol><li>Switch to <strong>Game Design</strong> scene by selecting <strong>Scenes-->Game Design</strong> from the main menu of MLLab IDE";
	$content=$content . "<li>Select <strong>Create Agent</strong> in the <strong>Game Design Commands</strong> panel";
	$content=$content . "<li>Create as many bots of different scripts as you like, do not generate <strong>UserBot</strong>(remember that in " . markup_stepLink("PlayGame") . " that <strong>UserBot</strong> is for user to control only). Also, create and train your copies of <strong>LaBot</strong> as done in " . markup_stepLink("CreateTrainBot") . ". " . markup_figureLink("figure16.gif") . " shows the bots created from various bots scripts";
	$content=$content . "<li>Select <strong>Simulate</strong> in the <strong>Game Design Commands</strong> panel. When this is done, various bots begins to move around 3D terrain and interact and fight against each other, as shown in " . markup_figureLink("figure17.gif") . ". Note that during this simulation process, all bots work autonomously and users will not need any control. The competency of the <strong>LaBot</strong> will then be tested on whether it can survive the simulated battle field";
	$content=$content . "</ol>";
	$content=$content . markup_figureImg("figure16.gif", "Create Bots with various Bot Scripts") . "<br />";
	$content=$content . markup_figureImg("figure17.gif", "Simulation in progress") . "<br />";
	$content=$content . "MLLab also comes with a convenient browser for user to observe the current states of various bots during the simulation, to access to the browser, select <strong>Toolkits-->Web Browser</strong>. " . markup_figureLink("figure18.gif") . " shows the browser after its launch. The transparency of the browser can be tuned through its slider bar and the browser can be moved around by right-pressing the browser and draging</p>";
	$content=$content . markup_figureImg("figure18.gif", "Browser for Simulation") . "<br />";
	$content=$content . "Just for fun, the user can also change the weather inside the MLLab simulation environment by clicking on the <strong>Climate</strong> button at the bottom bar of MLLab IDE and change the weather to snow or raining. " . markup_figureLink("figure21.gif") . " shows simulated battle in snows";
	$content=$content . markup_figureImg("figure21.gif", "Simulated Battle in Snows") . "<br />";
	$content=$content . markup_stepTitle("UploadData", "Upload Simulation Data");
	$content=$content . "<p>" . markup_stepLink("PlayGame") . " - " . markup_stepLink("SimulateCompete") . " form an iterative process in which a bot created using certain computational intelligence can be continuously improved. MLLab also allows user to upload the simulation data onto the website and displayed in the page <a href=\"mllabscoreboard.php\" class=\"yellow-text-underline\">Bot Scores</a> during the simulation process. To do this, perform the following steps";
	$content=$content . "<ol><li>Login to the website through MLLab IDE. Select <strong>Toolkits-->Web Connect</strong> from the main menu of MLLab IDE. The <strong>Web Connect</strong> login page appear as shown in " . markup_figureLink("figure20.gif") . ". The username and password is the same as the one you use to login to this website";
	$content=$content . "<li>After successfully logining, you are connected to the site, therefore whenever you perform simulation by selecting <strong>Simulate</strong> in the <strong>Game Design</strong> scene, the simulation will be transmitted to the site. In other words, you will be able to view the simulation data through the web site link <a href=\"mllabscoreboard.php\" class=\"yellow-text-underline\">Bot Scores</a> which is automatically updated whenever the simulation is running in the MLLab IDE";
	$content=$content . "</ol>";
	$content=$content . markup_figureImg("figure20.gif", "Web Connect Login form") . "<br />";
	$content=$content . "</p>";
	$content=$content . "</div>";
	mllabbody("MLLab Quick Tutorial", $content);
	echo "</body></html>";
}
else
{
	$_SESSION['current_request']='mllabdownload.php';
	header('location: mllab.php');
}
?>