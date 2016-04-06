import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import junit.framework.*;

public class Exception1Test extends TestCase{

	@Before
	public void setUp() throws Exception {
		super.setUp();
	}

	@After
	public void tearDown() throws Exception {
		super.tearDown();
	}

	@Test
	public void test1(){
		String exception="/ by zero";
		String exceptionreturned= Exception1.runtimeError(5,0);
		assertEquals(exception,exceptionreturned);
	}

	public void test2(){
		String exception="No error encountered";
		String exceptionreturned= Exception1.runtimeError(25,5);
		assertEquals(exception,exceptionreturned);
	}

}
