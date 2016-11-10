//
//  ViewController.swift
//  24Points
//
//  Created by Wu Jian on 09/11/2016.
//  Copyright © 2016 Baresi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var lblNumbers: UILabel!
    
    @IBOutlet weak var lblFormular: UILabel!
    
    @IBOutlet weak var btnRunit: UIBarButtonItem!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        btnRunit.title = "RunIt"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        var swiftCallback: () -> Void = getFormular
        registerCallback (swiftCallback)
    }

    @IBAction func runIt(_ sender: Any)
    {
        generateCards();
    }

    func getFormular(cStringPointer: UnsafeMutablePointer<UnsafePointer<Int8>>)
    {
        guard let strFormular = String.fromCString(cStringPointer.memory) else { return nil }

        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0)) 
        {
            dispatch_async(dispatch_get_main_queue()) {
                self.lblFormular.text = strFomular
            }   
        }
    }
}

