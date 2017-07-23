package fuzzylogic.application;

import java.awt.Color;

import fuzzylogic.*;
import fuzzylogic.membership.*;
import fuzzylogic.gui.*;
import visualizer.simpleui.SimpleUI;

public class Console {
	public static void main(String[] args)
	{
		RuleInferenceEngine rie=new RuleInferenceEngine();
		
		FuzzySet output=new FuzzySet("Output", -100, 100, 1);
		output.addMembership("Cooling", new FuzzyReverseGrade(-50, 0, Color.green));
		output.addMembership("Zero", new FuzzyTriangle(-50, 0, 50, Color.blue));
		output.addMembership("Heating", new FuzzyGrade(0, 50, Color.red));
		rie.addFuzzySet(output.getName(), output);
		
		FuzzySet tempError=new FuzzySet("Temperature Error", -4, 4, 0.05);
		tempError.addMembership("Negative", new FuzzyReverseGrade(-2, 0, Color.green));
		tempError.addMembership("Zero", new FuzzyTriangle(-2, 0, 2, Color.blue));
		tempError.addMembership("Positive", new FuzzyGrade(0, 2, Color.red));
		rie.addFuzzySet(tempError.getName(), tempError);
		
		
		FuzzySet tempErrorDot=new FuzzySet("Temperature Error", -10, 10, 0.1);
		tempErrorDot.addMembership("Negative", new FuzzyReverseGrade(-5, 0, Color.green));
		tempErrorDot.addMembership("Zero", new FuzzyTriangle(-5, 0, 5, Color.blue));
		tempErrorDot.addMembership("Positive", new FuzzyGrade(0, 5, Color.red));
		rie.addFuzzySet(tempErrorDot.getName(), tempErrorDot);
		
		/*
		1. If (e < 0) AND (er < 0) then Cool 0.5 & 0.0 = 0.0
		2. If (e = 0) AND (er < 0) then Heat 0.5 & 0.0 = 0.0
		3. If (e > 0) AND (er < 0) then Heat 0.0 & 0.0 = 0.0
		4. If (e < 0) AND (er = 0) then Cool 0.5 & 0.5 = 0.5
		5. If (e = 0) AND (er = 0) then No_Chng 0.5 & 0.5 = 0.5
		6. If (e > 0) AND (er = 0) then Heat 0.0 & 0.5 = 0.0
		7. If (e < 0) AND (er > 0) then Cool 0.5 & 0.5 = 0.5
		8. If (e = 0) AND (er > 0) then Cool 0.5 & 0.5 = 0.5
		9. If (e > 0) AND (er > 0) then Heat 0.0 & 0.5 = 0.0
		*/
		
		Rule rule=new Rule("Rule 1");
		rule.addAntecedent(new Clause(tempError, "Is", "Negative"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Negative"));
		rule.setConsequent(new Clause(output, "Is", "Cooling"));
		rie.AddRule(rule);
		
		rule=new Rule("Rule 2");
		rule.addAntecedent(new Clause(tempError, "Is", "Zero"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Negative"));
		rule.setConsequent(new Clause(output, "Is", "Heating"));
		rie.AddRule(rule);
		
		rule=new Rule("Rule 3");
		rule.addAntecedent(new Clause(tempError, "Is", "Positive"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Negative"));
		rule.setConsequent(new Clause(output, "Is", "Heating"));
		rie.AddRule(rule);
		
		rule=new Rule("Rule 4");
		rule.addAntecedent(new Clause(tempError, "Is", "Negative"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Zero"));
		rule.setConsequent(new Clause(output, "Is", "Cooling"));
		rie.AddRule(rule);
		
		rule=new Rule("Rule 5");
		rule.addAntecedent(new Clause(tempError, "Is", "Zero"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Zero"));
		rule.setConsequent(new Clause(output, "Is", "Zero"));
		rie.AddRule(rule);
		
		rule=new Rule("Rule 6");
		rule.addAntecedent(new Clause(tempError, "Is", "Positive"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Zero"));
		rule.setConsequent(new Clause(output, "Is", "Heating"));
		rie.AddRule(rule);
		
		rule=new Rule("Rule 7");
		rule.addAntecedent(new Clause(tempError, "Is", "Negative"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Positive"));
		rule.setConsequent(new Clause(output, "Is", "Cooling"));
		rie.AddRule(rule);
		
		rule=new Rule("Rule 8");
		rule.addAntecedent(new Clause(tempError, "Is", "Zero"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Positive"));
		rule.setConsequent(new Clause(output, "Is", "Cooling"));
		rie.AddRule(rule);
		
		rule=new Rule("Rule 9");
		rule.addAntecedent(new Clause(tempError, "Is", "Positive"));
		rule.addAntecedent(new Clause(tempErrorDot, "Is", "Positive"));
		rule.setConsequent(new Clause(output, "Is", "Heating"));
		rie.AddRule(rule);
		
		tempError.setX(-1.0);
		System.out.println("For Temperature Error: ");
		System.out.println("Negative: "+tempError.getMembership("Negative").degree(-1.0));
		System.out.println("Zero: "+tempError.getMembership("Zero").degree(-1.0));
		System.out.println("Positive: "+tempError.getMembership("Positive").degree(-1.0));
		
		tempErrorDot.setX(2.5);
		System.out.println("For Temperature Error Dot: ");
		System.out.println("Negative: "+tempErrorDot.getMembership("Negative").degree(2.5));
		System.out.println("Zero: "+tempErrorDot.getMembership("Zero").degree(2.5));
		System.out.println("Positive: "+tempErrorDot.getMembership("Positive").degree(2.5));
		
		rie.infer(output);
		
		System.out.println("output: "+output.getX());
		
		FuzzySetCanvas tempCanvas=new FuzzySetCanvas("Output", output);
		FuzzySetCanvas tempErrorCanvas=new FuzzySetCanvas("Temp Error", tempError);
		FuzzySetCanvas tempErrorDotCanvas=new FuzzySetCanvas("Temp Error Dot", tempErrorDot);
		
		SimpleUI.display(tempCanvas);
		SimpleUI.display(tempErrorCanvas);
		SimpleUI.display(tempErrorDotCanvas);
	}
}
