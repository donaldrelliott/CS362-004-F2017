/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
import junit.framework.TestCase;
import java.util.Random;
/**
 * Performs Validation Test for url validations.
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {
   public UrlValidatorTest(String testName) {
      super(testName);
   }
/*
 * Testing completed by Donald Elliott, Eric Lord, and Chowdhury Tanveer Anzoom
 * Final Project for CS362-400
 * Due Date: 12/4/2017
 */ 
   // Add more URLs if you all want to
   public void testManualTest() {
		ResultPair[] urlTests = {
				// Begin testing URLs that should be correct
				new ResultPair("http://192.168.1.1/", true),
				new ResultPair("http://github.com", true),
				new ResultPair("http://www.github.com/donaldrelliott", true),
				new ResultPair("http://www.cnn.com", true),
				new ResultPair("http://www.yahoo.com", true),
				new ResultPair("http://www.amazon.com", true),
				new ResultPair("https://www.google.com", true),
				new ResultPair("https://www.google.bg", true),
				new ResultPair("https://www.google.co.jp", true),
				new ResultPair("https://www.google.com.vn", true),
				new ResultPair("http://www.reddit.com", true),
				new ResultPair("http://www.oregonstate.edu", true),
				new ResultPair("https://www.oregonstate.instructure.com/login", true),
				new ResultPair("httP://www.cnn.com", true),
				new ResultPair("httP://www.foxnews.com", true),
				new ResultPair("httP://www.msnbc.com", true),
				new ResultPair("https://www.udacity.com", true),
				new ResultPair("ftp://127.0.0.1", true),
				new ResultPair("https://www.apple.com/iphone/", true),
				new ResultPair("https://www.androidauthority.com/oneplus-5-android-8-oreo-oxygenos-open-beta-817716/", true),
				// Begin Testing URLs that should be false
				new ResultPair("http://289.425.158.321", false),
				new ResultPair("http//www.apple.com/iphone/", false),
				new ResultPair("httpr://www.amazon.com/", false),
				new ResultPair("http:\\www.yahoo.com", false),
				new ResultPair("ftpq://www1.oregonstate.instructure.com/login", false),
				new ResultPair("ftp:127.0.0.1", false)
		    	};
		   	int urlIndex = 0;
		   	String expected, returned;
		   	boolean e, r; // To match expected and returned
		   	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   	System.out.println("---------------");
		   	System.out.println("MANUAL TESTS");
		   	while (urlIndex < urlTests.length) {   
			   // Value in ResultPair
			   e = urlTests[urlIndex].valid;
			   expected = (e) ? "VALID" : "INVALID"; 
			   // Value returned from isValid()
			   r = urlVal.isValid(urlTests[urlIndex].item);
			   returned = (r) ? "VALID" : "INVALID";
			   	// Test failed
			   	if (!expected.equals(returned)) {
					System.out.println("TESTING " + expected + " URL: " + urlTests[urlIndex].item);
					System.out.println("-- TEST FAILED. EXPECTED: " + expected + ". RETURNED: " + returned + "\n"); 
			   	}
			   	// Test passed
			   	else
					System.out.println("TESTING " + expected + " URL: " + urlTests[urlIndex].item);
			   	urlIndex++;
		   	}
		   	System.out.println("\n---------------\n");
	   	}
/*
 * START DONALD'S PARTITION TESTING FUNCTIONS
 */
   // TESTING FOR SCHEME
   public void testYourFirstPartition() {
	   System.out.println("TESTING SCHEME");
	   // Should be true, true, false, true
	   String[] schemeToTest = {"http://", "h3t://", "://", ""};
	   UrlValidator schemeVal = new UrlValidator(schemeToTest, 0);
	   for (int i = 0; i < schemeToTest.length; i++) {
		   String schemeValue = schemeToTest[i];
		   System.out.println("TESTING " + schemeValue);
		   String newSchemeTest = schemeValue;
		   boolean valid = schemeVal.isValidScheme(newSchemeTest);
		   if (valid == false)
			   System.out.println("RESULT: FAILED. INVALID SCHEME.");
		   else
			   System.out.println("RESULT: PASSED");
	    }
	   	System.out.println("\n---------------\n");
   }
   
   // TESTING FOR AUTHORITY
   public void testYourSecondPartition() {
	   System.out.println("TESTING AUTHORITY");
	   String[] authorityToTest = {"oregonstate.edu", "256.134.", "www.google.com", "apple~.com", "4.c.rj"};
	   UrlValidator authorityValue = new UrlValidator(authorityToTest, 0);
	   for (int i = 0; i < authorityToTest.length; i++) {
		   String authorityVal = authorityToTest[i];
		   System.out.println("TESTING " + authorityVal);
		   String newTestAuthority = authorityVal;
		   boolean valid = authorityValue.isValidAuthority(newTestAuthority);
		   if (valid == false)
			   System.out.println("RESULT: FAILED. INVALID AUTHORITY");
		   else
			   System.out.println("RESULT: PASSED");
	    }
	   	System.out.println("\n---------------\n");
   }
  
  // TESTING FOR PORTS
  public void testYourThirdPartition() {
    System.out.println("TESTING PORT");
    // Testing values of ports from 2 digits up to 5. All should
    // return as passing unless there is an error.
    String[] portsToTest = {"80", "3535", "423", "25487"};
    UrlValidator newValues = new UrlValidator(portsToTest, 0);
    for (int i = 0; i < portsToTest.length; i++) {
      String testingPort = portsToTest[i];
      System.out.println("TESTING " + "www.google.com:" + testingPort);
      // Save what is to be tested into a new string.
      String newTestURL = "www.google.com:" + testingPort;
      // Send new string to isValidAuthority and check the port
      boolean valid = newValues.isValidAuthority(newTestURL);
      // If invalid, let us know.
      if (valid == false)
       System.out.println("RESULT: FAILED. INVALID PORT NUMBER.");
      // If valid, let us know that as well.
      else
    	  	System.out.println("RESULT: PASSED");
    }
    // Separate from next testing block.
   	System.out.println("\n---------------\n");
  }

  // TESTING FOR PATH
  public void testYourFourthPartition(){
    System.out.println("TESTING PATH");
    String[] pathsToTest = {"/test1", "//test1", "/", "test1", "..", "/test2/"};
    UrlValidator pathVal = new UrlValidator(pathsToTest, 0);
    for (int i = 0; i < pathsToTest.length; i++) {
      String newPath = pathsToTest[i];
      System.out.println("TESTING: " + newPath);
      String newPathTest = newPath;
      boolean valid = pathVal.isValidPath(newPathTest);
      if (valid == false)
        System.out.println("RESULT: FAILED. INVALID PATH.");
      else
    	  	System.out.println("RESULT: PASSED");
    }
   	System.out.println("\n---------------\n");
  }

  // TESTING QUERY
  public void testYourFifthPartition() {
    System.out.println("TESTING QUERIES");
    String[] queriesToTest = {"?action=view", "?action=edit&mode=up", "", "?search=itemNum"};
    UrlValidator pathQuery = new UrlValidator(queriesToTest, 0);
    for (int i = 0; i < queriesToTest.length; i++) {
      String testingQuery = queriesToTest[i];
      System.out.println("TESTING www.google.com/path" + testingQuery);
      String newQueryTest = "www.google.com/path" + testingQuery;
      boolean valid = pathQuery.isValidQuery(newQueryTest);
      if(valid == false)
    	  	// If not valid, let us know
        System.out.println("RESULT: FAILED. INVALID QUERY");
      else
    	  	// If valid let us know as well
    	  	System.out.println("RESULT: PASSED");
    }
    // Separate from next testing block
   	System.out.println("\n---------------\n");
  }
  
/*
* START ERIC'S PARTITION TESTING FUNCTIONS
*/
  // Partition testing: Scheme
  public void testSchemePartition(){
	   int numTestsFailed = 0;
	   int numTestsTotal = 0;
	   int testResult;
	   //Create URL/expected result pairs to test scheme partition
	   ResultPair[] partitionTestSchemes = {
		   new ResultPair("http://", true),
		   new ResultPair("https://", true),
		   new ResultPair("ftp://", true),
		   new ResultPair("", true),
		   new ResultPair("h3tp://", true),
		   new ResultPair("h12-+.-://", true),
		   new ResultPair("http", false),
		   new ResultPair("://", false),
		   new ResultPair("http//", false),
		   new ResultPair("http:", false),
		   new ResultPair("http:://", false),
		   new ResultPair("http:/", false),
		   new ResultPair("http:///", false),
		   new ResultPair("3tp://", false),
	   };
	   numTestsTotal = partitionTestSchemes.length;
	   //Run tests and tally the number of failures
	   System.out.println("\n===============================");
	   System.out.println("Running Partition Test for Scheme");
	   System.out.println("_________________________________");
	   for(int i = 0; i < numTestsTotal; i++){
		   //Create new URL with selected scheme, and validate.
		   ResultPair testToRun = new ResultPair(partitionTestSchemes[i].item + "www.example.com", partitionTestSchemes[i].valid);
		   String testInfo = "Scheme:'" + partitionTestSchemes[i].item + "'";
		   testResult = runTest(testToRun, testInfo, true, UrlValidator.ALLOW_ALL_SCHEMES);
		   if(testResult == 1)
			   numTestsFailed++;
	   }
	   System.out.println("________________________________________________");
	   System.out.println("Scheme Partition Test Results:  " + numTestsTotal + " tests run, " + numTestsFailed + " tests failed.");
	   System.out.println("=================================================\n");
  }

//Partition testing: Authority
  public void testAuthorityPartition(){
	   int numTestsFailed = 0;
	   int numTestsTotal = 0;
	   int testResult;
	   //Create URL/expected result pairs to test authority partition
	   ResultPair[] partitionTestAuthority = {
		   new ResultPair("www.example.com", true),
		   new ResultPair("example.com", true),
		   new ResultPair("userid:password@example.com", true),
		   new ResultPair("255.255.255.255/", true),
		   new ResultPair("1337.net/", true),
		   new ResultPair("example.it", true),
		   new ResultPair("example.c0m", false),
		   new ResultPair("example.rt", true),
		   new ResultPair("example.-cm", false),
		   new ResultPair("256.256.256.256", false),
		   new ResultPair("", false),
		   new ResultPair(".com", false),
		   new ResultPair("@.com", false),
		   new ResultPair(".", false),
		   new ResultPair("125.125.125", false),
		   new ResultPair("0.0.0.0.0", false),
		   new ResultPair("255.255.255", false),
		   new ResultPair("255", false),
		   new ResultPair("example.c m", false)
	   };
	   numTestsTotal = partitionTestAuthority.length;
	   //Run tests and tally the number of failures
	   System.out.println("\n==================================");
	   System.out.println("Running Partition Test for Authority");
	   System.out.println("____________________________________");

	   for(int i = 0; i < numTestsTotal; i++){
		   //Create new URL with selected authority, and validate
		   ResultPair testToRun = new ResultPair("http://" + partitionTestAuthority[i].item, partitionTestAuthority[i].valid);
		   String testInfo = "Authority:'" + partitionTestAuthority[i].item + "'";
		   testResult = runTest(testToRun, testInfo, true, UrlValidator.ALLOW_ALL_SCHEMES);
		   if(testResult == 1)
			   numTestsFailed++;
	   }
	   System.out.println("____________________________________");
	   System.out.println("Authority Partition Test Results:  " + numTestsTotal + " tests run, " + numTestsFailed + " tests failed.");
	   System.out.println("==================================\n");
  }

  // Partition testing: Port
  public void testPortsPartition(){
	   int numTestsFailed = 0;
	   int numTestsTotal = 0;
	   int testResult;
	   //Create URL/expected result pairs to test port partition
	   ResultPair[] partitionTestPort = {
			   new ResultPair(":10000", true),
			   new ResultPair(":1", true),
			   new ResultPair(":0", false),
			   new ResultPair(":65535", true),
			   new ResultPair(":65536", false),
			   new ResultPair(":", false),
			   new ResultPair(":abc", false),
			   new ResultPair(":256.256", false),
			   new ResultPair(":100abc", false),
			   new ResultPair(":999999999999999", false),
			   new ResultPair(":-1", false),
	   };
	   numTestsTotal = partitionTestPort.length;
	   //Run tests and tally the number of failures
	   System.out.println("\n=============================");
	   System.out.println("Running Partition Test for Port");
	   System.out.println("_______________________________");

	   for(int i = 0; i < numTestsTotal; i++){
		   //Create new URL with selected port, and validate.
		   ResultPair testToRun = new ResultPair("http://www.example.com" + partitionTestPort[i].item, partitionTestPort[i].valid);
		   String testInfo = "Port:'" + partitionTestPort[i].item + "'";
		   testResult = runTest(testToRun, testInfo, true, UrlValidator.ALLOW_ALL_SCHEMES);
		   if(testResult == 1)
			   numTestsFailed++;
	   }
	   System.out.println("_______________________________");
	   System.out.println("Port Partition Test Results:  " + numTestsTotal + " tests run, " + numTestsFailed + " tests failed.");
	   System.out.println("=============================\n");
  }

  // Partition testing: Path
  public void testPathPartition(){
	   int numTestsFailed = 0;
	   int numTestsTotal = 0;
	   int testResult;

	   //Create URL/expected result pairs to test path partition
	   ResultPair[] partitionTestPath = {
			   new ResultPair("/test", true),
			   new ResultPair("/test/testfile", true),
			   new ResultPair("/", true),
			   new ResultPair("", true),
			   new ResultPair("//", false),
			   new ResultPair("//test/testfile", false),
			   new ResultPair("test/testfile", false)
	   };
	   numTestsTotal = partitionTestPath.length;
	   //Run tests and tally the number of failures
	   System.out.println("\n=============================");
	   System.out.println("Running Partition Test for Path");
	   System.out.println("_______________________________");

	   for(int i = 0; i < numTestsTotal; i++){
		   //Create new URL with selected port, and validate.
		   ResultPair testToRun = new ResultPair("http://www.example.com" + partitionTestPath[i].item, partitionTestPath[i].valid);
		   String testInfo = "Path:'" + partitionTestPath[i].item + "'";
		   testResult = runTest(testToRun, testInfo, true, UrlValidator.ALLOW_ALL_SCHEMES);
		   if(testResult == 1)
			   numTestsFailed++;
	   }
	   System.out.println("_______________________________");
	   System.out.println("Path Partition Test Results:  " + numTestsTotal + " tests run, " + numTestsFailed + " tests failed.");
	   System.out.println("=============================\n");
  }

//Partition testing: Query
  public void testQueryPartition(){
	   int numTestsFailed = 0;
	   int numTestsTotal = 0;
	   int testResult;

	   //Create URL/expected result pairs to test query partition
	   ResultPair[] partitionTestQuery = {
			   new ResultPair("?param=value", true),
			   new ResultPair("?param1=value1&param2=value2", true),
			   new ResultPair("?", true),
			   new ResultPair("?param", true),
			   new ResultPair("", true),
			   new ResultPair("??", false),
			   new ResultPair("?param=value&&", false),
			   new ResultPair("?param1=value1?param2=value2", false)
	   };
	   numTestsTotal = partitionTestQuery.length;
	   //Run tests and tally the number of failures
	   System.out.println("\n==============================");
	   System.out.println("Running Partition Test for Query");
	   System.out.println("________________________________");

	   for(int i = 0; i < numTestsTotal; i++){
		   //Create new URL with selected query, and validate.
		   ResultPair testToRun = new ResultPair("http://www.example.com" + partitionTestQuery[i].item, partitionTestQuery[i].valid);
		   String testInfo = "Query:'" + partitionTestQuery[i].item + "'";
		   testResult = runTest(testToRun, testInfo, true, UrlValidator.ALLOW_ALL_SCHEMES);
		   if(testResult == 1)
			   numTestsFailed++;
	   }
	   System.out.println("________________________________");
	   System.out.println("Query Partition Test Results:  " + numTestsTotal + " tests run, " + numTestsFailed + " tests failed.");
	   System.out.println("==============================\n");
  }

  public int runTest(ResultPair url, String testInfo, boolean showResult, long schemeOption){
	   String validatorSetting = "";

	   // default validator setting
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   //Can set validator differently
	   if (schemeOption == 2) {
		   urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_2_SLASHES);
		   validatorSetting = " Option = ALLOW_2_SLASHES";
	   }
	   if (schemeOption == 3) {
		   urlVal = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
		   validatorSetting = " Option = NO_FRAGMENTS";
	   }
	   if (schemeOption == 4) {
		   urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
		   validatorSetting = " Option = ALLOW_LOCAL_URLS";
	   }

	   if(urlVal.isValid(url.item) == url.valid)
		   return 0;
	   else{
		   String report = "TEST FAILED: URL='" + url.item + "', Expected:'" + url.valid + "' .isValid():'" + !url.valid + "', " + testInfo;
		   if (showResult)
			   System.out.println(report + validatorSetting);
		   return 1;
	   }
  }

// BEGIN testIsValid	
  public void testIsValid() {
	   int failCount = 0;
	   int schemeIndex, authorityIndex, portIndex, pathIndex, queryIndex;
	   String currentScheme, currentAuthority, currentPort, currentPath, currentQuery;
	   boolean schemeFlag, authorityFlag, portFlag, pathFlag, queryFlag;
	   Random rand = new Random();
	   System.out.println("\n------------------------------------------");
	   System.out.println("******** BEGIN RANDOMIZED TESTING ********");
	   for(int i = 0;i<250;i++){
		   schemeIndex = rand.nextInt(testUrlScheme.length);
		   currentScheme = testUrlScheme[schemeIndex].item;
		   authorityIndex = rand.nextInt(testUrlAuthority.length);
		   currentAuthority = testUrlAuthority[authorityIndex].item;
		   portIndex = rand.nextInt(testUrlPort.length);
		   currentPort = testUrlPort[portIndex].item;
		   pathIndex = rand.nextInt(testPath.length);
		   currentPath = testPath[pathIndex].item;
		   queryIndex = rand.nextInt(testUrlQuery.length);
		   currentQuery = testUrlQuery[queryIndex].item;
		   //Append scheme, authority, port, path and query
		   String testUrl = currentScheme + currentAuthority + currentPort + currentPath + currentQuery;
		   schemeFlag = testUrlScheme[schemeIndex].valid;
		   authorityFlag = testUrlAuthority[authorityIndex].valid;
		   portFlag = testUrlPort[portIndex].valid;
		   pathFlag = testPath[pathIndex].valid;
		   queryFlag = testUrlQuery[queryIndex].valid;
		   //Logical AND between valid flags
		   boolean expected = schemeFlag && authorityFlag && portFlag && pathFlag && queryFlag;
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean result = urlVal.isValid(testUrl);
		   if (result == expected) {
			  System.out.println("PASS -->" + " URL: " + testUrl);
			  System.out.println("EXPECTED: " + expected + ". ACTUAL: " + result + "."); 
		   }
		   else {
			  System.out.println("\n******** FAILURE FOUND ********");
			  System.out.println("* FAIL -->" + " URL: " + testUrl);
			  System.out.println("* EXPECTED: " + expected + ". ACTUAL: " + result + ".");
			  System.out.println("*****************************\n");
			  failCount++;
		   }
	   }
	   System.out.println("------------------------------");
	   System.out.println("***** " + failCount + " OUT OF " + 250 + " TESTS FAILED" + " *****");
  }
  
  ResultPair[] testUrlScheme = { new ResultPair("http://", true),
          new ResultPair("ftp://", true),
          new ResultPair("h3t://", true),
          new ResultPair("h+t://", true),
          new ResultPair("ht.://", true),
          new ResultPair("ttp//", true),
          new ResultPair("3ht://", false),
          new ResultPair("http:/", false),
          new ResultPair("http:", false),
          new ResultPair("http/", false),
          new ResultPair(":/", false),
          new ResultPair("://", false),
          new ResultPair("", true)
  };

  ResultPair[] testUrlAuthority = { new ResultPair("www.google.com", true),
		  new ResultPair("oregonstate.edu", true),
		  new ResultPair("defense.gov", true),
		  new ResultPair("travel.br", true),
		  new ResultPair("255.255.255.255", true),
          new ResultPair("256.256.256.256", false),
          new ResultPair(".samsung.com", false),
          new ResultPair("5463.com", true),
          new ResultPair("nytimes", false),
          new ResultPair(".nytimes", false),
          new ResultPair("467.255.255.255", false),
          new ResultPair("0.0.0.0", true),
          new ResultPair("255.255.255.255.265", false),
          new ResultPair(".35.255.124.56", false),
          new ResultPair("tesla.lmp", false),
          new ResultPair("", false),
  };
  
  ResultPair[] testUrlPort = { new ResultPair(":80", true),
		   new ResultPair(":1005", true),
		   new ResultPair(":65535", true),
		   new ResultPair(":65536", false),
		   new ResultPair(":rstp", false),
		   new ResultPair(":-3", false),
		   new ResultPair("75", false),
		   new ResultPair(":999a", false),
		   new ResultPair(":10dt23", false),
		   new ResultPair("", true)
  };

  ResultPair[] testPath = { new ResultPair("/testscene", true),
		   new ResultPair("/d456tm", true),
		   new ResultPair("/$77", true),
		   new ResultPair("//testing", false),
		   new ResultPair("//testing1/testing2", false),
		   new ResultPair("", true),
		   new ResultPair("/#", false),
		   new ResultPair("/#/fileX", false),
		   new ResultPair("/dir100/file7", true),
		   new ResultPair("/..", false),
		   new ResultPair("/../", false),
		   new ResultPair("/test1/", true),
		   new ResultPair("/file1/testcase", true),
		   new ResultPair("/..//file", false)
  };

  ResultPair[] testUrlQuery = { new ResultPair("?action=view", true),
		   new ResultPair("?action=edit&mode=up", true),
		   new ResultPair("?q=website+with+query&rlz=111", true),
		   new ResultPair("?q=website with query&rlz=111", false),
		   new ResultPair("", true)
  };

  // A couple unit tests are below
   public void testisValidQuery() {
	   UrlValidator val = new UrlValidator();
	   System.out.println("TESTING isValidQuery");
	   System.out.println("TESTING QUERY: ?page=12&view=454");
	   System.out.println("RESULT: " + val.isValidQuery("?page=12&view=454"));
	   System.out.println("TESTING QUERY: ?action=addToCart");
	   System.out.println("RESULT: " + val.isValidQuery("?action=addToCart"));
	   System.out.println("TESTING QUERY: null");
	   System.out.println("RESULT: " + val.isValidQuery(""));
   }
   public void testisValidScheme() {
 	  UrlValidator val = new UrlValidator();
 	  System.out.println("TESTING isValidScheme");
 	  System.out.println("TESTING SCHEME: http");
 	  System.out.println("RESULT: " + val.isValidScheme("http"));
 	  System.out.println("TESTING SCHEME: http:");
 	  System.out.println("RESULT: " + val.isValidScheme("http:"));
 	  System.out.println("TESTING SCHEME: http:/");
 	  System.out.println("RESULT: " + val.isValidScheme("http:/"));
 	  System.out.println("TESTING SCHEME: http://");
 	  System.out.println("RESULT: " + val.isValidScheme("http://"));
 	  System.out.println("TESTING SCHEME: https");
 	  System.out.println("RESULT: " + val.isValidScheme("https"));
 	  System.out.println("TESTING SCHEME: h3t://");
 	  System.out.println("RESULT: " + val.isValidScheme("h3t://"));
 	  System.out.println("TESTING SCHEME: ftp");
 	  System.out.println("RESULT: " + val.isValidScheme("ftp"));
 	  System.out.println("TESTING SCHEME: ://");
 	  System.out.println("RESULT: " + val.isValidScheme("://"));
 	 System.out.println("\n---------------\n");
   }
}
