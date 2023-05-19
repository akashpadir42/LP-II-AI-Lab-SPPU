import java.util.Scanner;

public class HospitalExpertSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the Hospitals and Medical Facilities Expert System!");
        System.out.println("Please answer the following questions to find suitable medical facilities for you.");

        System.out.println("What is your location?");
        String location = scanner.nextLine();

        System.out.println("Do you prefer a public or private hospital? (Enter 'public' or 'private')");
        String hospitalType = scanner.nextLine();

        System.out.println("Do you need specialized medical services? (Enter 'yes' or 'no')");
        String needSpecializedServices = scanner.nextLine();

        System.out.println("Do you require emergency services? (Enter 'yes' or 'no')");
        String needEmergencyServices = scanner.nextLine();

        System.out.println("Based on your preferences, here are the recommended medical facilities:");

        if (hospitalType.equalsIgnoreCase("public")) {
            System.out.println("1. Public Hospital A");
            System.out.println("2. Public Hospital B");
        } else if (hospitalType.equalsIgnoreCase("private")) {
            System.out.println("1. Private Hospital X");
            System.out.println("2. Private Hospital Y");
        } else {
            System.out.println("Invalid hospital type entered.");
            System.exit(0);
        }

        if (needSpecializedServices.equalsIgnoreCase("yes")) {
            System.out.println("3. Specialized Medical Center");
        }

        if (needEmergencyServices.equalsIgnoreCase("yes")) {
            System.out.println("4. Emergency Clinic");
        }

        System.out.println("Thank you for using the Hospitals and Medical Facilities Expert System!");
    }
}
